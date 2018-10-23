//Header ==> function declarations

#include <iostream>
#include <vector>

#include "LearningSet.h"
#include "muestra.h"

using namespace std;

#ifndef KNN_H
#define KNN_H

class KNN {
public:
	void mathDistance();
	void learning(LearningSet);
	void recovery();
	void validation();
	void printMatriz();
private:
	vector<muestra> MatrizDatos;
	float PorcentajeEficiencia;
};
#endif
