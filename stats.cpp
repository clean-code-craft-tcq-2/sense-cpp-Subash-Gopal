#include "stats.h"

namespace Statistics {    
    Stats ComputeStatistics(const std::vector<double>& input_vector ) {
        Stats compute;
        compute.max = *(std::max_element(input_vector.begin(), input_vector.end()));
        compute.min = *(std::min_element(input_vector.begin(), input_vector.end()));
        compute.average = (std::accumulate(input_vector.begin(), input_vector.end(),0.0L)) / input_vector.size();    
        return compute;
    }
}

