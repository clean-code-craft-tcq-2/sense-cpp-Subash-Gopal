#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"

#include <cmath>

TEST_CASE("reports average, minimum and maximum") {
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
    auto computedStats = Statistics::ComputeStatistics({NAN,NAN,NAN});
    REQUIRE(std::isnan(computedStats.min));
    REQUIRE(std::isnan(computedStats.max));
    REQUIRE(std::isnan(computedStats.average));
}

TEST_CASE("raises alerts when max is greater than threshold") {
    EmailAlert emailAlert;
    LEDAlert ledAlert;
    IAlerter *alertObj = new IAlerter();
    alertObj->emailAlert = &emailAlert;
    alertObj->ledAlert = &ledAlert;
    std::vector<IAlerter*> alerters = {alertObj};
    
    //const float maxThreshold = 10.2;
    StatsAlerter statsAlerter(100.0, alerters);
    statsAlerter.checkAndAlert({99.8, 34.2, 4.5, 6.7});

    REQUIRE(emailAlert.emailSent);
    REQUIRE(ledAlert.ledGlows);
}
