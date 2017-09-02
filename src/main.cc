#include "bicron/bicron.h"
#include "bicron/json_config_builder.h"

#include <cstdlib> // EXIT_SUCCESS, EXIT_FAILURE
#include <string>
#include <fstream>
#include <iostream>
#include <streambuf>

std::string help(std::string const& cmd);

int main(int argc, char** argv)
{
	bool        flag_help = false;
	std::string arg_path  = "";

	for (int i = 1; i < argc; ++i)
	{
		std::string const arg = argv[i];
		if (arg == "-h")
		{
			flag_help = true;
			break;
		}
		else
		{
			arg_path = arg;
			break;
		}
	}

	if (flag_help or argc < 2)
	{
		std::cerr << help(std::string(argv[0])) << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream cfg(arg_path);
	if (not cfg.is_open())
	{
		std::cerr << help(std::string(argv[0])) << std::endl;
		std::cerr << "Unable to open file: '" << arg_path << "'" << std::endl;
		return EXIT_FAILURE;
	}

	std::string json_config(
		(std::istreambuf_iterator<char>(cfg)),
		std::istreambuf_iterator<char>());

	bicron::Bicron bc;
	bc.update(bicron::parse_json(json_config));

	auto const result = bc.status();
	for (auto const& pair : result)
	{
		std::cout << pair.first << ":" << pair.second << std::endl;
	}

	return EXIT_SUCCESS;
}

std::string help(std::string const& cmd)
{
	return
		"Usage\n"
		"  " + cmd + " -h\n"
		"  " + cmd + " <configuration file path>";
}
