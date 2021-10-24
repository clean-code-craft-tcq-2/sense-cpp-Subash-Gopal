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
    float maximumThreshold;
    IAlerter *address0;
    public:
    StatsAlerter(const float maxThreshold,const std::vector<IAlerter*>& alerters)
    { 
        maximumThreshold = maxThreshold;
        address0 = alerters[0];
    }
    void checkAndAlert(const std::vector<double>& input_vector)
    {
        IAlerter objAlert;
        double max = *(std::max_element(input_vector.begin(), input_vector.end()));
        if(max > maximumThreshold){
             *address0->emailAlert = {true};
             *address0->ledAlert = {true};
        }
        else{
            *address0->emailAlert = {false};
            *address0->ledAlert = {false};
        }
    }
    
};
