#pragma once

#include "time_point.h"

#include <string>

class Rule
{
public:
	Rule(TimePoint tp, std::string key, std::string val);

	std::string key() const;
	std::string val() const;

private:
	TimePoint   const _tp;
	std::string const _key;
	std::string const _val;
};
