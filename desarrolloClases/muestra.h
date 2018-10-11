//Header ==> function declarations

#include <iostream>
#include <vector>
#include "sensores.h"

using namespace std;

#ifndef muestra_H
#define muestra_H

class muestra {
public:
	vector<float> standardDev;
	string clase;
private:
	void setStandardDeviation(vector<sensores>, int);
	float doMath(vector<int>);
	vector<float> arithmeticMean(vector<int>);
	vector<float> standardDeviation(vector<int>);
};
#endif
