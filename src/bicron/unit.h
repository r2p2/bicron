#pragma once

#include <limits>

namespace bicron
{

template <int min, int max>
class Unit
{
public:
	Unit() = default;
	Unit(Unit const&) = default;
	Unit& operator=(Unit const&) = default;
	Unit(Unit&&) = default;
	Unit& operator=(Unit&&) = default;

	explicit Unit(int)
	: _is_set(true)
	, _value(value)
	{
	}

	bool is_valid() const
	{
		return _value >= min and _value <= max;
	}

	int value() const
	{
		return _value;
	}

	void value(int value)
	{
		_is_set = true;
		_value  = value;
	}

	bool is_set() const
	{
		return _is_set;
	}

	void reset()
	{
		_is_set = false;
	}

private:
	bool _is_set = false;
	int  _value  = {};
};

typedef Unit< 0, std::numeric_limits<int>::max()> Year;
typedef Unit< 0, 12>                              Month;
typedef Unit< 0, 31>                              Day;
typedef Unit<-1, 23>                              Hour;
typedef Unit<-1, 59>                              Minute;

}
