#include "rule.h"

Rule::Rule(TimePoint tp, std::string key, std::string val)
: _tp(std::move(tp))
, _key(std::move(key))
, _val(std::move(val))
{
}

bool Rule::is_matching(TimePoint const& tp) const
{
	return
		(not _tp.has_year()   or _tp.year()   >= tp.year())   and
		(not _tp.has_month()  or _tp.month()  >= tp.month())  and
		(not _tp.has_day()    or _tp.day()    >= tp.day())    and
		(not _tp.has_hour()   or _tp.hour()   >= tp.hour())   and
		(not _tp.has_minute() or _tp.minute() >= tp.minute());
}
