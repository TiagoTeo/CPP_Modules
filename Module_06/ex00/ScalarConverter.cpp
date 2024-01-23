#include <ScalarConverter.hpp>

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter's Default Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void) other;
	std::cout << "ScalarConverter's Copy Constructor called" << std::endl;
}

// Destructor
ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter's Destructor called" << std::endl;
}

// Operators
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
	(void) other;
	return *this;
}

void	ScalarConverter::converter(int value)
{
	std::cout << "char: ";
	if (value < 32 || value > 126)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void	ScalarConverter::converter(char value)
{
	std::cout << "char: '" << value << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void	ScalarConverter::converter(double value)
{
	std::cout << "char: ";
	if (value < 32 || value > 126)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	if (value >  std::numeric_limits<int>::max() || value <  std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	if (value > static_cast<double>(std::numeric_limits<float>::max()) || value < static_cast<double>(-FLT_MAX))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << value << std::endl;
}

void	ScalarConverter::converter(float value)
{
	std::cout << "char: ";
	if (value < 32 || value > 126)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	if (value > static_cast<float>(std::numeric_limits<int>::max()) || value < static_cast<float>(std::numeric_limits<int>::min()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << value << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

const char *ScalarConverter::ImpossibleConversion::what() const throw() {
	std::stringstream res;
	res << "char: " << "impossible" << std::endl;
    res << "int: " << "impossible" << std::endl;
    res << "float: " << "nanf" << std::endl;
    res << "double: " << "nan" << std::endl;
	return (res.str().c_str());
}

void	ScalarConverter::ScalarConverter::displayLimits(std::string Flimit, std::string Dlimit)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << Flimit << std::endl;
	std::cout << "double: " << Dlimit << std::endl;

	exit(1);
}

void	ScalarConverter::converter(std::string value)
{
	const std::string Flimits[4] = {"inff", "-inff", "+inff", "nanf"};
	const std::string Dlimits[4] = {"inf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 4; i++ )
	{
		if (value == Flimits[i] || value == Dlimits[i])
			displayLimits(Flimits[i], Dlimits[i]);
	}
	converterType(value);
}

void	ScalarConverter::converterType(std::string value)
{
	const std::string existingTypes[4] = {"int", "char", "float", "double"};
	std::string type = getType(value);
	
	int i = 0;

	while (i < 4 && existingTypes[i].compare(type))
		i++;
	switch (i + 1) {
	case 1:
	{
		std::istringstream numberStream(value);
		int	valueInt;
		numberStream >> valueInt; 
		return converter(valueInt);
	}
	case 2:
		return converter(value[0]);
	case 3:
	{
		std::istringstream numberStream(value);
		float	valueFloat;
		numberStream >> valueFloat; 
		return converter(valueFloat);
	}
	case 4:
	{
		std::istringstream numberStream(value);
		double	valueDouble;
		numberStream >> valueDouble; 
		return converter(valueDouble);
	}
	}
}