#include <vector>

namespace Statistics {
    
    class Stats
    {
    public:
        double average;
        float max;
        float min;
    };
    
    Stats ComputeStatistics(const std::vector<float>& );
}
