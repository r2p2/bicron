#include "config.h"

void Config::add(Rule rule)
{
	_rules.push_back(std::move(rule));
}

std::vector<Rule> Config::rules() const
{
	return _rules;
}
