#include <time_point.h>

#include <catch.hpp>

using namespace bicron;

TEST_CASE("validity of time points", "[time_point]")
{
	REQUIRE(TimePoint().is_valid()                              == true);
	REQUIRE(TimePoint().year(2017).is_valid()                   == true);
	REQUIRE(TimePoint().year(-5).is_valid()                     == false);
	REQUIRE(TimePoint().year(2017).month(12).day(24).is_valid() == true);
	REQUIRE(TimePoint().year(2017).month(13).day(24).is_valid() == false);
}
