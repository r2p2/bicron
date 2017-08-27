#include "time_point.h"

TimePoint::TimePoint(int year, int month, int day, int hour, int minute)
: _year(year)
, _month(month)
, _day(day)
, _hour(hour)
, _minute(minute)
{
}

int TimePoint::year() const
{
	return _year;
}

int TimePoint::month() const
{
	return _month;
}

int TimePoint::day() const
{
	return _day;
}

int TimePoint::hour() const
{
	return _hour;
}

int TimePoint::minute() const
{
	return _minute;
}

bool TimePoint::is_valid() const
{
	return
		_year   >  0 and
		_month  >  0 and _month  < 13 and
		_day    >  0 and _day    < 32 and
		_hour   >= 0 and _hour   < 24 and
		_minute >= 0 and _minute < 60;
}
