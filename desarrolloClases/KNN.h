//Header ==> function declarations

#include <iostream>
#include <vector>
#include <math.h>

#include "LearningSet.h"
#include "sample.h"
#include "RecoverySet.h"

using namespace std;

#ifndef KNN_H
#define KNN_H

class KNN {
public:
	KNN(int);
	float mathDistance(sample, sample);
	void learning(LearningSet);
	string recovery(sample);
	int validation(sample);
	void printArray();
private:
	int k;
	vector<sample> dataArray;
	float PorcentajeEficiencia;
};
#endif
