#include "time_point.h"

TimePoint& TimePoint::year(int year)
{
	_year.value(year);
	return *this;
}

TimePoint& TimePoint::month(int month)
{
	_month.value(month);
	return *this;
}

TimePoint& TimePoint::day(int day)
{
	_day.value(day);
	return *this;
}

TimePoint& TimePoint::hour(int hour)
{
	_hour.value(hour);
	return *this;
}

int TimePoint::year() const
{
	return _year.value();
}

int TimePoint::month() const
{
	return _month.value();
}

int TimePoint::day() const
{
	return _day.value();
}

int TimePoint::hour() const
{
	return _hour.value();
}

int TimePoint::minute() const
{
	return _minute.value();
}

bool TimePoint::is_valid() const
{
	return
		(not _year.is_set()   or _year.is_valid())  and
		(not _month.is_set()  or _month.is_valid()) and
		(not _day.is_set()    or _day.is_valid())   and
		(not _hour.is_set()   or _hour.is_valid())  and
		(not _minute.is_set() or _minute.is_valid());
}
