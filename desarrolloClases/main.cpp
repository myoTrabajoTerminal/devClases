#include <iostream>
#include <sstream>
#include <fstream>

#include "sensores.h"

using namespace std;

vector<vector<string>> readCSV(string ruta);
vector<sensores> fillSensores(vector<vector<string>> raws);
void printVal(vector<vector<string>> raws);
void printSensores(vector<sensores> data);

int main(int argc, char* argv[]) {
	int periodo = 20;
	vector<vector<string>> res;
	vector<sensores> conjuntos;

	res = readCSV("excel/valores-final.csv");
	conjuntos = fillSensores(res);

	printSensores(conjuntos);

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

vector<sensores> fillSensores(vector<vector<string>> raws) {
	vector<sensores> out;
	sensores aux;
	int fin, content;
	string id;
	for (int row = 0; row < raws.size(); row++) {
		fin = raws[row].size() - 1;
		id = raws[row][fin];
		//cout << id << '\t' << aux.getClase() << endl;
		if (aux.getClase() == id){
			for (int sensor = 0; sensor < raws[row].size() - 1; sensor++) {
				stringstream stream(raws[row][sensor]);
				stream >> content;
				aux.append(sensor + 1, content);
			}
		}
		else {
			out.push_back(aux);
			aux.setClase(id);
			aux.clearVector();
		}
	}
	return out;
}

void printVal(vector<vector<string>> raws) {
	int index = 1;
	while (raws[index] == raws[index + 1] || index + 1 != raws.size() - 1) {
		for (int col = 0; col < raws[index].size(); col++) {
			cout << raws[index][col] << '\t';
		}
		cout << endl;
		index++;
	}
}

void printSensores(vector<sensores> data) {
	for (int conj = 0; conj < data.size(); conj++) {
		cout << endl << endl << "********" << data[conj].getClase() << "********" << endl << endl;
		for (int sensor = 0; sensor < 8; sensor++) {
			data[conj].printVector(sensor + 1);
			cout << endl << endl;
		}
	}
}