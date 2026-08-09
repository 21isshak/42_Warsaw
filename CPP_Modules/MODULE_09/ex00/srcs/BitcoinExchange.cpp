#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
    *this = rhs;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs) {
        this->_db = rhs._db;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::trim(std::string &str) const
{
    size_t first = str.find_first_not_of(" \t");
    if(first == std::string::npos)
    {
        str = "";
        return;
    }
    size_t last = str.find_last_not_of(" \t");
    str = str.substr(first, (last - first + 1));
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if(date.length() != 10)
        return false;
    if(date[4] != '-' || date[7] != '-')
        return false;
    
    int year;
    int month;
    int day;
    std::stringstream ssY(date.substr(0, 4));
    std::stringstream ssM(date.substr(5, 2));
    std::stringstream ssD(date.substr(8, 2));
    if(!(ssY >> year) || !(ssM >> month) || !(ssD >> day))
        return false;

    if(year < 2000 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if(month == 2 && day > 29)
        return false;

    if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string &valStr, float &val) const
{
    char *endptr;
	val = std::strtof(valStr.c_str(), &endptr);

	if(*endptr != '\0')
	{
		std::cerr << "Error: bad input => " << valStr << std::endl;
		return false;
	}

	if(val < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}

	if(val > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}

	return true;
}

bool BitcoinExchange::loadDatabase(const std::string &dbPath)
{
	std::ifstream file(dbPath.c_str());
	if(!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return false;
	}

	std::string line;
	std::getline(file, line);
	while(std::getline(file, line))
	{
		size_t commaPos = line.find(',');
		if(commaPos != std::string::npos)
		{
			std::string date = line.substr(0, commaPos);
			std::string rateStr = line.substr(commaPos + 1);

			trim(date);
			trim(rateStr);

			float rate = std::atof(rateStr.c_str());
			_db[date] = rate;
		}
	}
	file.close();
	return true;
}

void BitcoinExchange::processInputFile(const std::string &inputPath)
{
	std::ifstream file(inputPath.c_str());
	if(!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);

	while(std::getline(file, line))
	{
		if(line.empty()) 
			continue;

		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pipePos);
		std::string valStr = line.substr(pipePos + 1);

		trim(date);
		trim(valStr);

		if(!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		float value;
        if(!isValidValue(valStr, value))
		{
            continue;
        }

		std::map<std::string, float>::const_iterator it = _db.find(date);

		if(it != _db.end())
			std::cerr << date << " => " << value << " = " << (value * it->second) << std::endl;

		else
		{
			it = _db.upper_bound(date);

			if (it == _db.begin())
				std::cerr << "Error: date too old => " << date << std::endl;
			else
			{
				--it;
				std::cerr << date << " => " << value << " = " << (value * it->second) << std::endl;
			}
		}
	}
	file.close();
}
