#include "KNN.h"

KNN::KNN(int val) {
	k = val;
}

float KNN::mathDistance(sample test, sample tester) {
	float aux = 0;
	for (int sensor = 0; sensor < test.getStandarDev().size(); sensor++) {
		aux = aux + pow((test.getStandarDev()[sensor] - tester.getStandarDev()[sensor]),2);
	}
	return sqrt(aux);
}

void KNN::learning(LearningSet raws) {
	for (int row = 0; row < raws.getStandarDeviations().size(); row++) {
		dataArray.push_back(raws.getStandarDeviations()[row]);
	}
}

string KNN::recovery(sample dataTest) {
	float aux;
	float out = mathDistance(dataTest, dataArray[0]);
	string match = dataArray[0].getClase();
	for (int record = 1; record < dataArray.size(); record++) {
		aux = mathDistance(dataTest, dataArray[record]);
		if (aux < out){
			out = aux;
			match = dataArray[record].getClase();
		}
	}
	cout << match[0] << '\t' << dataTest.getClase()[0] << endl;
	return match;
}

int KNN::validation(sample dataTest) {
	string val = recovery(dataTest);
	if (dataTest.getClase() == val) {
		return 1;
	}
	else return 0;
}

void KNN::printArray() {
	for (int samp = 0; samp < dataArray.size(); samp++) {
		for (int clase = 0; clase < dataArray[samp].getClase().size(); clase++) {
			cout << dataArray[samp].getClase()[clase] << '[';
			for (int sensor = 0; sensor < dataArray[samp].getStandarDev().size(); sensor++) {
				cout << dataArray[samp].getStandarDev()[sensor] << ", ";
			}
			cout << ']' << endl;
		}
	}
}