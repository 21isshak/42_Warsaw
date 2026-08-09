#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <ostream>
#include <sstream>
#include <string>

class ScalarConverter {
   private:
	// make class non-instantiable (only static methods)
	ScalarConverter();
	ScalarConverter(ScalarConverter const&);
	ScalarConverter& operator=(ScalarConverter const&);
	// parsing
	static void parseInput(std::string &input);
	static bool isWrongInput(std::string &input);
	static bool isValidNumber(std::string &input);
	static bool isPseudo(std::string &input);

	// conversion
	static double stringToDouble(std::string &str);

	// print
	static bool isPrintableASCII(int i);
	static void printChar(double &value, std::string &input);
	static void printInt(double &value, std::string &input);
	static void printDouble(double &value, std::string &input);
	static void printFloat(double &value, std::string &input);

   public:
	static void convert(std::string &input);

	class WrongInputException : public std::exception {
	   public:
		virtual const char *what() const throw();
	};
};

#endif