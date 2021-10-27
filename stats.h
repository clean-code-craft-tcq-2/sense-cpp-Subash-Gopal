#include <vector>
#include <bits/stdc++.h>

namespace Statistics {
    struct Stats{
        double max;
        double min;
        double average;        
    };
    Stats ComputeStatistics(const std::vector<double>& input);
}

struct EmailAlert{
	  bool emailSent;
};
struct LEDAlert{
	  bool ledGlows;
};
struct IAlerter{
		EmailAlert* emailAlert;
		LEDAlert* ledAlert;
};

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
