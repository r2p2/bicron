#include <rule.h>

#include <catch.hpp>

TEST_CASE("matching rules", "[rule]")
{
	TimePoint now;
	now.year(2017).month(9).day(14).hour(12).minute(33);

	REQUIRE(Rule(TimePoint()           , "", "").is_matching(now) == true);
	REQUIRE(Rule(TimePoint().minute(30), "", "").is_matching(now) == true);
	REQUIRE(Rule(TimePoint().minute(34), "", "").is_matching(now) == false);
	REQUIRE(Rule(TimePoint().minute(33), "", "").is_matching(now) == true);
	REQUIRE(
		Rule(
			TimePoint()
				.hour(13)
				.minute(32), "", "").is_matching(now) == false);
	REQUIRE(
		Rule(
			TimePoint()
				.hour(11)
				.minute(34), "", "").is_matching(now) == true);
	REQUIRE(
		Rule(
			TimePoint().hour(11).minute(33), "", "")
				.is_matching(now) == true);
}
