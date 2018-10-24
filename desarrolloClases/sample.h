//Header ==> function declarations

#include <iostream>
#include <vector>
#include "sensors.h"

using namespace std;

#ifndef sample_H
#define sample_H

class sample{
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
