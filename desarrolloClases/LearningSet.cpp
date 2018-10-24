#include "LearningSet.h"

void LearningSet::setValues(vector<sample> raws) {
	for (int row = 0; row < raws.size(); row++) {
		standardDeviations.push_back(raws[row]);
	}
}

void LearningSet::append(sample val) {
	standardDeviations.push_back(val);
}

vector<sample> LearningSet::getStandarDeviations() {
	return standardDeviations;
}