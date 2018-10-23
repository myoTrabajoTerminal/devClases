//Header ==> function declarations

#include <iostream>
#include <vector>
#include "sensors.h"

using namespace std;

#ifndef muestra_H
#define muestra_H

class muestra{
public:
	void setStandardDeviation(sensors, int, int);
	float doMath(vector<int>);
	float arithmeticMean(vector<int>);
	float standardDeviation(vector<int>, float);
	vector<float> getStandarDev();
	void clear();
	void setClase(string);
	string getClase();
private:
	vector<float> standardDev;
	string clase;
};
#endif
