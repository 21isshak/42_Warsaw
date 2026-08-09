#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>


class BitcoinExchange
{
	private:
		std::map<std::string, float> _db;//map that will hold the data of database
	
		bool isValidDate(const std::string &date) const;
    	bool isValidValue(const std::string &valStr, float &val) const;
    	void trim(std::string &str) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &rhs);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);
		~BitcoinExchange();

		bool loadDatabase(const std::string &dbPath);
    	void processInputFile(const std::string &inputPath);

};


#endif