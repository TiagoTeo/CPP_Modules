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

bool BitcoinExchange::checkDate(std::string date) {
	std::istringstream dateStream(date);
	std::string yearString, monthString, dayString;
	int year, month, day;
	if (std::getline(dateStream, yearString, '-') && std::getline(dateStream, monthString, '-') && std::getline(dateStream, dayString)) {
		if (yearString.find_first_not_of("0123456789") == std::string::npos && \
			monthString.find_first_not_of("0123456789") == std::string::npos && \
			dayString.find_first_not_of("0123456789") == std::string::npos) {

				year = std::atof(yearString.c_str());
				month = std::atof(monthString.c_str());
				day = std::atof(dayString.c_str());

				if ((year > 0 && year < 2025) && (month > 0 && month < 13) && (day > 0 && day < 31))
					return (true);
			}
	}
	std::cout << "Error: bad date => " << date << std::endl;
	return (false);
}

bool BitcoinExchange::checkValue(std::string value) {
	double vDouble;
	if (value.find_first_not_of("0123456789.") == std::string::npos) {

		if (value.find_first_of('.') == value.find_last_of('.') && \
		value.find_first_of('.') != 0 && value.find_first_of('.') != value.size() - 1) {

			vDouble = std::atof(value.c_str());
			if (vDouble > 0 && vDouble < 1000)
				return (true);
		}
	}
	std::cout << "Error: bad value => " << value << std::endl;
	return (false);
}

void BitcoinExchange::execute() {
	std::string line, date, value;
	std::ifstream inputFile(_fileName.c_str());
	while (std::getline(inputFile, line)) {
		std::istringstream temp(line);
		if (line != "date | value") {
			if (std::getline(temp, date, '|') && std::getline(temp, value)) {

				date.erase(date.size() - 1, 1);
				value.erase(0, 1);

				if (checkDate(date) && checkValue(value))
					printResult(date, value);
			}
			else
				std::cout << "Error: bad input => " << line << std::endl;
		}
	}
}

void BitcoinExchange::printResult(std::string date, std::string value) {
	double vDouble = std::atof(value.c_str());
	std::map<std::string,double>::iterator it = _data.find(date);

	if (it == _data.end()) {
		it = _data.lower_bound(date);
		if (it != _data.begin())
			it--;
	}
	std::cout << date << " => " << value << " = " << it->second * vDouble << std::endl;
}