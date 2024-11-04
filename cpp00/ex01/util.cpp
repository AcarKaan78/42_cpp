#include "util.hpp"

std::string formatField(const std::string str)
{
	if (str.length() > 10)
	{
		return str.substr(0, 9) + ".";
	}
	else
	{
		return str;
	}
}
