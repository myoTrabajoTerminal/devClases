//Header ==> function declarations

#include <iostream>
#include <vector>
#include "sample.h"

using namespace std;

#ifndef RecoverySet_H
#define RecoverySet_H

class RecoverySet {
public:
	void setValues(vector<sample>);
	void append(sample);
	vector<sample> getStandarDeviations();
private:
	vector<sample> standardDeviations;
};

#endif