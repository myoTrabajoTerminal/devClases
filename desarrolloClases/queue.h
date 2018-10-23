//Header ==> function declarations

#include <iostream>
#include <vector>
#include "muestra.h"

using namespace std;

#ifndef Queue_H
#define Queue_H

class Queue {
public:
	void setValues(vector<muestra>);
	void append(muestra);
	vector<muestra> getStandarDeviations();
private:
	vector<muestra> standardDeviations;
};

#endif