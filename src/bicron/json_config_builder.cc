#include "json_config_builder.h"

namespace bicron
{

Config parse_json(std::string const& j)
{
	return parse(json::parse(j));
}

Config parse(json const& j)
{
	Config cfg;

	for (auto const& rule_cfg :  j["cron"])
	{
		TimePoint   tp;
		std::string key;
		std::string val;

		for (auto el = rule_cfg.cbegin(); el != rule_cfg.cend(); ++el)
		{
			if (el.key() == "year")
			{
				tp.year(el.value());
			}
			else if (el.key() == "month")
			{
				tp.year(el.value());
			}
			else if (el.key() == "day")
			{
				tp.day(el.value());
			}
			else if (el.key() == "hour")
			{
				tp.hour(el.value());
			}
			else if (el.key() == "minute")
			{
				tp.minute(el.value());
			}
			else if (el.key() == "key")
			{
				key = el.value();
			}
			else if (el.key() == "state")
			{
				val = el.value();
			}
		}

		if (key.empty())
			continue;

		cfg.add(Rule(std::move(tp), std::move(key), std::move(val)));
	}

	return cfg;
}


}
