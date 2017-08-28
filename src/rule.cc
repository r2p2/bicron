#include "rule.h"

Rule::Rule(TimePoint tp, std::string key, std::string val)
: _tp(std::move(tp))
, _key(std::move(key))
, _val(std::move(val))
{
}
