//Header ==> function declarations

#include <iostream>
#include <vector>

using namespace std;

#ifndef sensores_H
#define sensores_H

class sensores{
public:
	sensores();
	void setVector(int number, vector<int> data);
	void setClase(string cla);
	string getClase();
	void append(int sensor, int dato);
	void clearVector();
	void printVector(int sensor);
private:
	vector<int> sensor1;
	vector<int> sensor2;
	vector<int> sensor3;
	vector<int> sensor4;
	vector<int> sensor5;
	vector<int> sensor6;
	vector<int> sensor7;
	vector<int> sensor8;
	string clase;
};

#endif
