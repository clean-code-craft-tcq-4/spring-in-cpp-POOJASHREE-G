#include "stats.h"
#include <algorithm>
#include <numeric>

Statistics::Stats Statistics::ComputeStatistics(const std::vector<float>& vect) {
    //Implement statistics here

	float maxElement = *std::max_element(vect.begin(), vect.end());
	float minElement = *std::min_element(vect.begin(), vect.end());
	float average = accumulate( vect.begin(), vect.end(), 0.0/ vect.size());

	Statistics::Stats s;

	s.average = average;
	s.max = maxElement;
	s.min = minElement;

	return s;
}
