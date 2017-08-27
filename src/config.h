#pragma once

#include "rule.h"

#include<vector>

class Config
{
public:
	void add(Rule rule);

private:
	std::vector<Rule> _rule;
};
