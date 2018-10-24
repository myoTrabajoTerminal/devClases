#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>

#include "sensors.h"
#include "sample.h"
#include "LearningSet.h"
#include "RecoverySet.h"
#include "KNN.h"

#define nSENSORS 8

using namespace std;

vector<vector<string>> readCSV(string);
vector<sensors> fillSensors(vector<vector<string>>);
void printSensors(vector<sensors>);
void printSamples(vector<sample>);

int main(int argc, char* argv[]) {
	int time = 25;
	vector<vector<string>> res;
	vector<sensors> sets;
	vector<sample> muestras;
	sample aux;
	LearningSet out;
	float operationRes;
	KNN clasificador(1);
	RecoverySet test;
	int count = 0;
	float efectividad;

	//Leer los datos de la pulsera almacenados para pruebas
	res = readCSV("excel/valores-final.csv");
	//Llenado de la clase sensores para dividir por clases
	sets = fillSensors(res);
	
	//Ciclo para generar las muestras totales para el clasificador
	//printSensors(sets);
	for (int periodo = 0; periodo < sets[0].getVector(1).size() / time; periodo++) {
		for (int set = 0; set < sets.size(); set++) {
			//cout << set << ' ' << time * periodo << ' ' << time*(periodo + 1) << endl;
			//cout << endl << sets[set].getClass() << endl;
			aux.setStandardDeviation(sets[set], time*periodo, time*(periodo + 1));
			aux.setClase(sets[set].getClass());
			muestras.push_back(aux);
			aux.clear();
		}
	}
	//printSamples(muestras);

	//Ciclo para tomar unicamente el n% de las muestras para la fase de aprendizaje
	operationRes = (muestras.size() *75)/ 100;
	for (int row = 0; row < operationRes; row++) {
		out.append(muestras[row]);
	}
	//printSamples(out.getStandarDeviations());

	clasificador.learning(out);
	//clasificador.printArray();
	//cout << "************" << endl;
	for (int row = operationRes; row < muestras.size(); row++) {
		test.append(muestras[row]);
	}
	//printSamples(test.getStandarDeviations());
	
	for (int samp = 0; samp < test.getStandarDeviations().size(); samp++) {
		clasificador.recovery(test.getStandarDeviations()[samp]);
	}

	for (int samp = 0; samp < test.getStandarDeviations().size(); samp++) {
		count = count + clasificador.validation(test.getStandarDeviations()[samp]);
	}
	efectividad = (count * 100) / static_cast<double>(test.getStandarDeviations().size());
	cout << "Efectividad: " << efectividad << endl;

	return 0;
}

//Metodo de lectura de un archivo CSV
vector<vector<string>> readCSV(string ruta) {
	ifstream  data(ruta);
	vector<string> raw;
	vector<vector<string>> raws;

	string line;
	while (getline(data, line))
	{
		stringstream  lineStream(line);
		string        cell;
		while (getline(lineStream, cell, ','))
		{
			raw.push_back(cell);
			//cout << cell << '\t';
		}
		//cout << endl;
		raws.push_back(raw);
		raw.clear();
	}
	return raws;
}

//Metodo que realiza el procesamiento necesario para llenar cada uno de los sensores con su clase correspondiente
vector<sensors> fillSensors(vector<vector<string>> raws) {
	vector<sensors> out;
	sensors aux;
	int fin, content;
	string clase;
	fin = raws[1].size() - 1;
	clase = raws[1][fin];
	for (int row = 1; row < raws.size(); row++) {
		fin = raws[row].size() - 1;
		if (clase != raws[row][fin]) {
			out.push_back(aux);
			clase = raws[row][fin];
			aux.clearVector();
			row--;
			continue;
		}
		for (int sensor = 0; sensor < fin; sensor++) {
			stringstream stream(raws[row][sensor]);
			stream >> content;
			aux.append(sensor + 1, content);
			aux.setClass(clase);
		}
		
	}
	out.push_back(aux);
	return out;
}

//DEBUG
void printSensors(vector<sensors> raws) {
	for (int row = 0; row < raws.size(); row++) {
		for (int sensor = 1; sensor <= nSENSORS; sensor++) {
			cout << '[';
			raws[row].printVector(sensor);
			cout << ']' << endl;
		}
		cout << endl;
	}
}

//DEBUG
void printSamples(vector<sample> raws) {
	for (int row = 0; row < raws.size(); row++) {
		cout << raws[row].getClase() << '[';
		for (int pos = 0; pos < raws[row].getStandarDev().size(); pos++) {
			cout << raws[row].getStandarDev()[pos] << '\t';
		}
		cout << ']' << endl;
	}
}