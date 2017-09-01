#include "time_point.h"

namespace bicron
{

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

TimePoint& TimePoint::minute(int minute)
{
	_minute.value(minute);
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

bool TimePoint::has_year() const
{
	return _year.is_set();
}

bool TimePoint::has_month() const
{
	return _month.is_set();
}

bool TimePoint::has_day() const
{
	return _day.is_set();
}

bool TimePoint::has_hour() const
{
	return _hour.is_set();
}

bool TimePoint::has_minute() const
{
	return _minute.is_set();
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

}
