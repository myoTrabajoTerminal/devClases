#include "sample.h"

#define nSENSORS 8

void sample::setStandardDeviation(sensors data, int inicio, int fin) {
	vector<int> aux;
	for (int sensor = 1; sensor <= nSENSORS; sensor++) {
		//cout << "sensor " << sensor << endl;
		for (int iterator = inicio; iterator < fin; iterator++) {
			aux.push_back(data.getVector(sensor)[iterator]);
			//cout << data.getVector(sensor)[iterator] << ',';
		}
		standardDev.push_back(doMath(aux));
		aux.clear();
		//cout << endl;
	}
}

float sample::doMath(vector<int> vals) {
	return standardDeviation(vals, arithmeticMean(vals));
}

float sample::arithmeticMean(vector<int> vals) {
	float val = 0;
	for (int i = 0; i < vals.size(); i++) {
		val = val + vals[i];
	}
	return val/vals.size();
}

float sample::standardDeviation(vector<int> vals, float mean) {
	float val = 0;
	for (int i = 0; i < vals.size(); i++) {
		val = val + pow(abs(vals[i] - mean), 2);
	}
	return sqrt(val / vals.size());
}

vector<float> sample::getStandarDev() {
	return standardDev;
}

void sample::clear() {
	standardDev.clear();
}

void sample::setClase(string cad) {
	clase = cad;
}

string sample::getClase() {
	return clase;
}