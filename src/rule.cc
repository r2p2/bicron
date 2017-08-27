#include "rule.h"

Rule::Rule(std::string key, std::string val)
: _key(std::move(key))
, _val(std::move(val))
{
}
