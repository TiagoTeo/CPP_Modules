#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string infile) : _fileName(infile) {
	if (!checkFile())
		throw badInputFile();
	fillData();
	execute();
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::checkFile() {
	std::ifstream fileName(_fileName.c_str());
	if (!fileName.good())
		return (false);
	return (true);
}

void BitcoinExchange::fillData() {
	std::ifstream dataFile("data.csv");
	if (!dataFile.good())
		throw badCsvFile();
	std::string line, date, value;
	while (std::getline(dataFile, line)) {
		std::istringstream temp(line);
		if (line != "date,exchange_rate" && \
			std::getline(temp, date, ',') && \
			std::getline(temp, value))
		_data[date] = std::atof(value.c_str());
	}
}

void BitcoinExchange::execute() {
	std::string line, date, value;
	std::ifstream inputFile(_fileName);
	while (std::getline(inputFile, line)) {
		std::istringstream temp(line);
		if (std::getline(temp, date, '|') && std::getline(temp, value))
			;//check date and value
		else
			std::cout << "Error: bad input => " << line << std::endl;
	}
}