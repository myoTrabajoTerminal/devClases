//Header ==> function declarations

#include <iostream>
#include <vector>
#include "sample.h"

using namespace std;

#ifndef LearningSet_H
#define LearningSet_H

class LearningSet {
public:
	void setValues(vector<sample>);
	void append(sample);
	vector<sample> getStandarDeviations();
private:
	vector<sample> standardDeviations;
};

#endif