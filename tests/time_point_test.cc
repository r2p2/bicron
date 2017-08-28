#include <time_point.h>

#include <catch.hpp>

TEST_CASE("validity of time points", "[time_point]")
{
	REQUIRE(TimePoint(2017,  9, 14, 12, 22).is_valid() == true);
	REQUIRE(TimePoint(2037,  1,  1,  5, 30).is_valid() == true);
	REQUIRE(TimePoint( -37,  1,  1,  5, 30).is_valid() == false);
	REQUIRE(TimePoint(2017,  9, 32, 12, 22).is_valid() == false);
	REQUIRE(TimePoint(2017, 13, 12, 12, 22).is_valid() == false);
	REQUIRE(TimePoint(2017, 11, 12, 24, 22).is_valid() == false);
	REQUIRE(TimePoint(2017, 11, 12, 21, 60).is_valid() == false);
}
