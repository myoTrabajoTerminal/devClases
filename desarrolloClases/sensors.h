//Header ==> function declarations

#include <iostream>
#include <vector>

using namespace std;

#ifndef sensors_H
#define sensors_H

class sensors{
public:
	void setVector(int, vector<int>);
	void append(int, int);
	void clearVector();
	void printVector(int);
	vector<int> getVector(int);
	void setClass(string);
	string getClass();
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
