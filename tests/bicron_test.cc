#include <bicron.h>

#include <catch.hpp>

using namespace bicron;

TEST_CASE("standard", "[bicron]")
{
	Config cfg;
	cfg.add(Rule(TimePoint(), "0", "off"));
	cfg.add(Rule(TimePoint(), "1", "off"));
	cfg.add(Rule(TimePoint().hour(15).minute(30), "0", "on"));

	Bicron bc;
	bc.update(std::move(cfg));

	SECTION("15:00")
	{
		auto const result = bc.status(
			TimePoint().year(2016).month(9).day(13).hour(15).minute(25));

		REQUIRE(result.at("0") == "off");
		REQUIRE(result.at("1") == "off");
	}

	SECTION("15:35")
	{
		auto const result = bc.status(
			TimePoint().year(2016).month(9).day(13).hour(16).minute(35));

		REQUIRE(result.at("0") == "on");
		REQUIRE(result.at("1") == "off");
	}
}
