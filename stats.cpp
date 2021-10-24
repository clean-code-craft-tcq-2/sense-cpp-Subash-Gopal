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
class StatsAlerter
{
   int maximumThreshold;
    int *address0,*address1;
    public:
    StatsAlerter(const float maxThreshold,const std::vector<IAlerter*>& alerters)
    { 
        maximumThreshold = maxThreshold;
        address0 = alerters[0];
        address1 = alerters[1];
    }
    void checkAndAlert(const std::vector<double>& input_vector)
    {
        IAlerter objAlert;
        double max = *(std::max_element(input_vector.begin(), input_vector.end()));
        if(max > maximumThreshold){
             *address0 = {true};
             *address1 = {true};
        }
        else{
            *address0 = {false};
            *address1 = {false};
        }
    }
    
};
