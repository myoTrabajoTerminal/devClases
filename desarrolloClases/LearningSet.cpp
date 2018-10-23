#include "LearningSet.h"

void LearningSet::setValues(vector<muestra> raws) {
	for (int row = 0; row < raws.size(); row++) {
		standardDeviations.push_back(raws[row]);
	}
}

void LearningSet::append(muestra val) {
	standardDeviations.push_back(val);
}

vector<muestra> LearningSet::getStandarDeviations() {
	return standardDeviations;
}