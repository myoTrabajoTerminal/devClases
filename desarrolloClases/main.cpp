#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>

#include "sensors.h"
#include "muestra.h"
#include "LearningSet.h"

#define nSENSORS 8

using namespace std;

vector<vector<string>> readCSV(string);
vector<sensors> fillSensors(vector<vector<string>>);
void printSensors(vector<sensors>);
void printMuestras(vector<muestra>);

int main(int argc, char* argv[]) {
	int time = 20;
	vector<vector<string>> res;
	vector<sensors> sets;
	vector<muestra> muestras;
	muestra aux;
	LearningSet out;

	res = readCSV("excel/valores-final.csv");
	sets = fillSensors(res);
	
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
	//printMuestras(muestras);
	//out << endl << endl << muestras.size() << '\t' << sets.size();

	out.setValues(muestras);

	return 0;
}

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

void printMuestras(vector<muestra> raws) {
	for (int row = 0; row < raws.size(); row++) {
		cout << raws[row].getClase() << '[';
		for (int pos = 0; pos < raws[row].getStandarDev().size(); pos++) {
			cout << raws[row].getStandarDev()[pos] << '\t';
		}
		cout << ']' << endl;
	}
}