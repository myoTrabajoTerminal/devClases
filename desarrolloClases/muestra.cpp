#include "muestra.h"

#define nSENSORES 8

void muestra::setStandardDeviation(sensores data, int inicio, int fin) {
	for (int sensor = 1; sensor <= nSENSORES; sensor++) {
		cout << "sensor " << sensor << endl;
		for (int iterator = inicio; iterator < fin; iterator++) {
			cout << "I: " << inicio << "\tF: " << fin << '\t';
			cout << data.getVector(sensor)[iterator] << ' ';
			cout << endl;
		}
		cout << endl;
	}
}

float muestra::doMath(vector<int> vals) {
	float val = 3.5;
	return val;
}

vector<float> muestra::arithmeticMean(vector<int> vals) {
	vector<float> val;
	return val;
}

vector<float> muestra::standardDeviation(vector<int> vals) {
	vector<float> val;
	return val;
}