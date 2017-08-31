#pragma once

#include "rule.h"

#include <vector>

class Config
{
public:
	void add(Rule rule);

	std::vector<Rule> rules() const;

private:
	std::vector<Rule> _rules;
};
