#pragma once

#include "time_point.h"

#include <string>

namespace bicron
{

class Rule
{
public:
	Rule(TimePoint tp, std::string key, std::string val);

	std::string key() const;
	std::string val() const;

	bool is_matching(TimePoint const&) const;

private:
	TimePoint   const _tp;
	std::string const _key;
	std::string const _val;
};

}
