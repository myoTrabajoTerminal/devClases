#include "LearningSet.h"

void LearningSet::setValues(vector<muestra> raws) {
	for (int row = 0; row < raws.size(); row++) {
		standardDeviations.push_back(raws[row]);
	}
}
