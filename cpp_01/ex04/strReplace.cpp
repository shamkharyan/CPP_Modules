#include <string>
#include <iostream>

std::string strReplace(std::string original, std::string toReplace, std::string replaceWith)
{
	if (original.empty() || toReplace.empty())
		return original;

	std::string replaced;
	std::size_t start = 0;
	std::size_t pos;

	while (start < original.size())
	{
		pos = original.find(toReplace, start);
		if (pos == std::string::npos)
		{
			replaced += original.substr(start);
			break;
		}
		replaced += original.substr(start, pos - start);
		replaced += replaceWith;
		start = pos + toReplace.size();
	}
	return replaced;
}