#include "RecoverySet.h"

void RecoverySet::setValues(vector<sample> raws) {
	for (int row = 0; row < raws.size(); row++) {
		standardDeviations.push_back(raws[row]);
	}
}

void RecoverySet::append(sample val) {
	standardDeviations.push_back(val);
}

vector<sample> RecoverySet::getStandarDeviations() {
	return standardDeviations;
}