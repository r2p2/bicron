#include <json_config_builder.h>

#include <catch.hpp>

using namespace bicron;

TEST_CASE("parse json configuration", "[config]")
{
	auto const config = parse_json("{\"cron\": [ "
		"{\"key\": \"0\", \"state\": \"off\"},"
    	"{\"key\": \"1\", \"state\": \"off\"},"
		"{\"hour\": 8, \"key\": \"0\", \"state\": \"on\"},"
		"{\"hour\": 20, \"key\": \"0\", \"state\": \"off\"},"
		"{\"month\": 5, \"key\": \"1\", \"state\": \"on\" },"
		"{\"month\": 9, \"key\": \"1\", \"state\": \"off\"} ] }");

	auto const& rules = config.rules();
	REQUIRE(rules.size() == 6);
	REQUIRE(rules[4].key() == "1");
	REQUIRE(rules[4].val() == "on");
}
