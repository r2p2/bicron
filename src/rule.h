#pragma once

#include <string>

class Rule
{
public:
	Rule(std::string key, std::string val);

	std::string key() const;
	std::string val() const;

private:
	std::string const _key;
	std::string const _val;
};
