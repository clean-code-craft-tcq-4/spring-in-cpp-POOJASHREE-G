#include "stats.h"
#include <algorithm>
#include <numeric>

Statistics::Stats Statistics::ComputeStatistics(const std::vector<float>& vect) {
    //Implement statistics here
        Statistics::Stats s;
	
	if (!(vect.empty()))
	{
		float maxElement = *std::max_element(vect.begin(), vect.end());
		float minElement = *std::min_element(vect.begin(), vect.end());
		float average = accumulate(vect.begin(), vect.end(), 0.0) / vect.size();



		s.average = average;
		s.max = maxElement;
		s.min = minElement;
		
	}

	return s;
}
