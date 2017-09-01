#pragma once

#include "config.h"
#include "time_point.h"

#include <map>

namespace bicron
{

class Bicron
{
public:
	typedef std::string            key_t;
	typedef std::string            val_t;
	typedef std::map<key_t, val_t> result_t;

	void update(Config);

	result_t status() const;
	result_t status(TimePoint const&) const;
private:
	Config _config;
};

}
