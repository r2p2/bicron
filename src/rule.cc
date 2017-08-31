#include "rule.h"

Rule::Rule(TimePoint tp, std::string key, std::string val)
: _tp(std::move(tp))
, _key(std::move(key))
, _val(std::move(val))
{
}

std::string Rule::key() const
{
	return _key;
}

std::string Rule::val() const
{
	return _val;
}

bool Rule::is_matching(TimePoint const& tp) const
{
	if (_tp.has_year() and _tp.year() < tp.year())
		return true;

	if (_tp.has_year() and _tp.year() > tp.year())
		return false;

	if (_tp.has_month() and _tp.month() < tp.month())
		return true;

	if (_tp.has_month() and _tp.month() > tp.month())
		return false;

	if (_tp.has_day() and _tp.day() < tp.day())
		return true;

	if (_tp.has_day() and _tp.day() > tp.day())
		return false;

	if (_tp.has_hour() and _tp.hour() < tp.hour())
		return true;

	if (_tp.has_hour() and _tp.hour() > tp.hour())
		return false;

	if (_tp.has_minute() and _tp.minute() < tp.minute())
		return true;

	if (_tp.has_minute() and _tp.minute() > tp.minute())
		return false;

	return true;
}
