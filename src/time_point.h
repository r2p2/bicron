#pragma once

class TimePoint
{
public:
	TimePoint(int year, int month, int day, int hour, int minute);

	int year() const;
	int month() const;
	int day() const;
	int hour() const;
	int minute() const;

	bool is_valid() const;

private:
	int const _year;
	int const _month;
	int const _day;
	int const _hour;
	int const _minute;
};
