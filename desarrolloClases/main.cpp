#include <iostream>
#include <sstream>
#include <fstream>

#include "sensores.h"
#include "muestra.h"

#define nSENSORES 8

using namespace std;

vector<vector<string>> readCSV(string ruta);
vector<sensores> fillSensores(vector<vector<string>> raws, int tiempo);
void printSensores(vector<sensores> raws);

int main(int argc, char* argv[]) {
	int tiempo = 20;
	vector<vector<string>> res;
	vector<sensores> conjuntos;
	vector<muestra> muestras;
	muestra aux;

	res = readCSV("excel/valores-final.csv");
	conjuntos = fillSensores(res, tiempo);
	
	//printSensores(conjuntos);
	for (int periodo = 0; periodo < conjuntos[0].getVector(1).size() / tiempo; periodo++) {
		for (int conjunto = 0; conjunto < conjuntos.size(); conjunto++) {
			for (int sensor = 1; sensor <= nSENSORES; sensor++) {
				cout << "" << conjunto << ' ' << sensor << ' ' << tiempo * periodo << ' ' << tiempo*(periodo + 1) - 1 << endl;
				aux.setStandardDeviation(conjuntos[conjunto], tiempo*periodo, tiempo*(periodo + 1) - 1);
			}
			muestras.push_back(aux);
		}
	}
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

vector<sensores> fillSensores(vector<vector<string>> raws, int tiempo) {
	vector<sensores> out;
	sensores aux;
	int fin, content;
	string clase;
	fin = raws[1].size() - 1;
	clase = raws[1][fin];
	for (int sensor = 0; sensor < fin; sensor++) {
		stringstream stream(raws[1][sensor]);
		stream >> content;
		aux.append(sensor + 1, content);
	}
	for (int row = 1; row < raws.size(); row++) {
		fin = raws[row].size() - 1;
		if (clase == raws[row][fin]) {
			for (int sensor = 0; sensor < fin; sensor++) {
				stringstream stream(raws[row][sensor]);
				stream >> content;
				aux.append(sensor + 1, content);
			}
		}
		else {
			out.push_back(aux);
			clase = raws[row][fin];
			aux.clearVector();
		}
	}
	out.push_back(aux);
	return out;
}

void printSensores(vector<sensores> raws) {
	for (int row = 0; row < raws.size(); row++) {
		for (int sensor = 1; sensor <= 8; sensor++) {
			cout << '[';
			raws[row].printVector(sensor);
			cout << ']' << endl;
		}
		cout << endl;
	}
}