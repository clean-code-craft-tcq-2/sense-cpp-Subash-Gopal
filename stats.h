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
		EmailAlert* emailAlert;
		LEDAler* ledAlert;
	};
