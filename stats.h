#include <vector>

namespace Statistics {
    
    class Stats
    {
    public:
        float average;
        float max;
        float min;
    };
    
    Stats ComputeStatistics(const std::vector<float>& );
}
