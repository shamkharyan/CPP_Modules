#include <iostream>
#include <fstream>
#include <string>

std::string strReplace(std::string original, std::string toReplace, std::string replaceWith);

int main(int argc, char *argv[])
{
	if (argc == 4)
	{
		std::string inputFileName = argv[1];
		std::string outputFileName = inputFileName + ".replace";

		std::ifstream inputFile;
		inputFile.open(inputFileName.c_str());
		if (!inputFile.is_open())
		{
			std::cerr << "Can't open file." << std::endl;
			return (1);
		}
		
		std::ofstream outputFile;
		outputFile.open(outputFileName.c_str());
		if (!outputFile.is_open())
		{
			std::cerr << "Can't open file." << std::endl;
			return (1);
		}

		std::string line;
		while (std::getline(inputFile, line))
			outputFile << strReplace(line, argv[2], argv[3]) << std::endl;

		inputFile.close();
		outputFile.close();

	}
	else
		std::cout << "Wrong argument count." << std::endl;
	return (0);
}