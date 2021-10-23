#include <vector>

namespace Statistics {
    struct Stats{
        double max;
        double min;
        double average;        
    };
    Stats ComputeStatistics(const std::vector<double>& input);
}
