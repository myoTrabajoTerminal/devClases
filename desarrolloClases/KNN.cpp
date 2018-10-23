#include "KNN.h"

void KNN::mathDistance() {

}

void KNN::learning(LearningSet raws) {
	for (int row = 0; row < raws.getStandarDeviations().size(); row++) {
		MatrizDatos.push_back(raws.getStandarDeviations()[row]);
		/*for (int i = 0; i < raws.getStandarDeviations()[row].getClase().size(); i++) {
			cout << raws.getStandarDeviations()[row].getClase()[i] << endl;
		}*/
	}
}

void KNN::recovery() {

}

void KNN::validation() {

}

void KNN::printMatriz() {
	for (int mues = 0; mues < MatrizDatos.size(); mues++) {
		cout << '[';
		for (int val = 0; val < MatrizDatos[mues].getStandarDev().size(); val++) {
			cout << MatrizDatos[mues].getStandarDev()[val];
		}
		cout << ']' << endl;

	}
}