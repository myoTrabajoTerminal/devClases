//Header ==> function declarations

#include <iostream>
#include <vector>
#include "muestra.h"

using namespace std;

#ifndef LearningSet_H
#define LearningSet_H

class LearningSet {
public:
	void setValues(vector<muestra>);
private:
	vector<muestra> standardDeviations;
};

#endif