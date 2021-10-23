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
    //int x;
    //int y;
    public:
    statsAlerter(const float maxThreshold, const std::vector<IAlerter>& input_vector){
        maximumThreshold = maxThreshold;
        //int x =input_vector[0];
        //int y =input_vector[1];
        
    }
    IAlerter checkAndAlert(const std::vector<double>& input_vector){
        IAlerter objAlert;
        float max = *(std::max_element(input_vector.begin(), input_vector.end()));
        if(max > maximumThreshold){
            objAlert.emailAlert.emailSent = true;
            objAlert.ledAlert.ledGlows = true;
        }
        else{
            objAlert.emailAlert.emailSent = false;
            objAlert.ledAlert.ledGlows = false;
        }
    }
};
