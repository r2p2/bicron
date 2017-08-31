#include "bicron.h"

void Bicron::update(Config cfg)
{
	_config = std::move(cfg);
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

