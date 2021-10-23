#include <vector>
#include <bits/stdc++.h>

namespace Statistics {
    struct Stats{
        double max;
        double min;
        double average;        
    };
    struct EmailAlert 
	{
		bool emailSent;
	};
	struct LEDAlert 
	{
		bool ledGlows;
	};
    struct IAlerter
	{
		EmailAlert emailAlert;
		LEDAlert ledAlert;
	};
    Stats ComputeStatistics(const std::vector<double>& input);
}
