#pragma once

#include "unit.h"

namespace bicron
{

class TimePoint
{
public:
	TimePoint& year(int);
	TimePoint& month(int);
	TimePoint& day(int);
	TimePoint& hour(int);
	TimePoint& minute(int);

	int year() const;
	int month() const;
	int day() const;
	int hour() const;
	int minute() const;

	bool has_year() const;
	bool has_month() const;
	bool has_day() const;
	bool has_hour() const;
	bool has_minute() const;

	bool is_valid() const;

private:
	Year   _year;
	Month  _month;
	Day    _day;
	Hour   _hour;
	Minute _minute;
};

}
