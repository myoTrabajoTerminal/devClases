//Header ==> function declarations

#include <iostream>
#include <vector>
#include "sensores.h"

using namespace std;

#ifndef muestra_H
#define muestra_H

class muestra{
public:
	void setStandardDeviation(sensores, int, int);
	float doMath(vector<int>);
	vector<float> arithmeticMean(vector<int>);
	vector<float> standardDeviation(vector<int>);
private:
	vector<float> standardDev;
	string clase;
};
#endif
