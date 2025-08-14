
#include "BitcoinExchange.hpp"


// Constructors

BitcoinExchange::BitcoinExchange()
{
	readDatabase();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	this->map = other.map;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
		this->map = other.map;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

// Getters
std::map<std::string, double> const &BitcoinExchange::getMap() const
{
	return (map);
}

void BitcoinExchange::readDatabase()
{
       std::ifstream file("data.csv");
        if (!file.is_open())
            throw CouldNotOpenFile();

        std::string line;

        //// Check if first line is date,exchange_rate
        std::getline(file, line);
        if (line != "date,exchange_rate")
            throw InvalidColumnFormat();

        while (std::getline(file, line))
		{
            std::string date, price;
            std::istringstream ss(line);
            std::getline(ss, date, ',');
            std::getline(ss, price);

            // Parse price using istringstream
            double priceValue;
            std::istringstream priceStream(price);
            if (!(priceStream >> priceValue))
				throw InvalidPriceFormat();
            map[date] = priceValue;
        }

        file.close();
}

void BitcoinExchange::execute(char const *fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open())
		throw CouldNotOpenFile();

	std::string line;

	// Check if first line is date,exchange_rate
	std::getline(file, line);
	if (line != "date | value")
		throw InvalidColumnFormat();

	while (std::getline(file, line))
	{
		std::string date;
		std::string valueStr;
		double priceValue;
		std::istringstream ss(line);
		std::getline(ss, date, '|');
		std::getline(ss, valueStr);

		// Validate date format.
        if (date.size() == 11 && date[10] == ' ')
            date = date.erase(date.length() - 1);
        else
        {
            std::cout << "Error: bad format" << std::endl;
			continue;
        }
		if (validateDate(date) == false)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		// Parse price using istringstream
		if(!valueStr.empty() && valueStr[0] == ' ')
			valueStr = valueStr.erase(0, 1);
        else
        {
            std::cout << "Error: bad format" << std::endl;
			continue;
        }
		priceValue = validatePrice(valueStr);
		if (priceValue != -1)
			showLineMap(date, priceValue);
		
	}

	file.close();
}

// Validate date format that it contains only numbers and '-'. And the month block is between 01 and 12 and the day block is between 01 and 31.
bool BitcoinExchange::validateDate(std::string const &date)
{
	for (size_t j = 0; j < 10; j++)
	{
		if ((j == 4 && date[j] == '-') || (j == 7 && date[j] == '-'))
			continue;
		if (isdigit(date[j]) == true)
			continue;
	}

	if (date[5] == '0' && date[6] == '0') 
		return (false);
	if ((date[5] == '1' && date[6] > '2') || date[5] > '1')
		return (false);

	if (date[8] == '0' && date[9] == '0')
		return (false);
	if ((date[8] == '3' && date[9] > '1') || date[8] > '3')
		return (false);
	
	return (true);
}

double BitcoinExchange::validatePrice(std::string const &valueStr)
{
	double priceValue;
	std::istringstream priceStream(valueStr);

	if (!(priceStream >> priceValue))
	{
		std::cout << "Error: bad value input => " << valueStr << std::endl;
		return (-1);
	}

	if (priceValue < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (-1);
	}
	else if (priceValue > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (-1);
	}
	
	return (priceValue);
}

void BitcoinExchange::showLineMap(std::string const &date, double price)
{
	std::map<std::string, double>::iterator it = map.find(date);
	if (it != map.end())
		std::cout << date << " => " << price << " = " << price * it->second << std::endl;
	else
	{
		std::map<std::string, double>::iterator it2 = map.lower_bound(date);
		if (it2 == map.begin())
			std::cout << date << " => " << price << " = " << price * it2->second << std::endl;
		else
		{
			it2--;
			std::cout << date << " => " << price << " = " << price * it2->second << std::endl;
		}
	}
}