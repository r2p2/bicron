#include <catch.hpp>

unsigned int fact(unsigned int number)
{
	return number <= 1 ? number : fact(number-1)*number;
}

TEST_CASE("factorials are computed", "[factorial]" )
{
    REQUIRE(fact(1)  ==       1);
    REQUIRE(fact(2)  ==       2);
    REQUIRE(fact(3)  ==       6);
    REQUIRE(fact(10) == 3628800);
}

