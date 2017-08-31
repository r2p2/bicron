#include "bicron.h"

void Bicron::update(Config cfg)
{
	_config = std::move(cfg);
}

Bicron::result_t Bicron::status() const
{
	TimePoint tp;
	time_t tt_now = time(0);
	tm* now;

	bool use_local_time = true;
	if (use_local_time)
		now = localtime(&tt_now);
	else
		now = gmtime(&tt_now);

	tp.year(1900 + now->tm_year);
	tp.month(1 + now->tm_mon);
	tp.day(now->tm_mday);
	tp.hour(now->tm_hour);
	tp.minute(now->tm_min);

	return status(tp);
}

Bicron::result_t Bicron::status(TimePoint const& tp) const
{
	result_t result;

	for (auto const& rule : _config.rules())
	{
		if (not rule.is_matching(tp))
			continue;

		result[rule.key()] = rule.val();
	}

	return result;
}

