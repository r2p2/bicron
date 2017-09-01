#pragma once

#include "rule.h"

#include <vector>

namespace bicron
{

class Config
{
public:
	void add(Rule rule);

	std::vector<Rule> rules() const;

private:
	std::vector<Rule> _rules;
};

}
