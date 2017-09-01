#pragma once

#include "config.h"

#include <json.hpp>

using json = nlohmann::json;

namespace bicron
{

Config parse_json(std::string const& j);

Config parse(json const& j);

}
