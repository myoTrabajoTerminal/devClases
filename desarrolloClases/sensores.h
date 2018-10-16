//Header ==> function declarations

#include <iostream>
#include <vector>

using namespace std;

#ifndef sensores_H
#define sensores_H

class sensores{
public:
	void setVector(int, vector<int>);
	void append(int, int);
	void clearVector();
	void printVector(int);
	vector<int> getVector(int);
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
