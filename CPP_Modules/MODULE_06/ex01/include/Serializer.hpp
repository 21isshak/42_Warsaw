#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
	std::string str;
	int num;
	char ch;
	float fl;
	double dbl;
};

class Serializer
{
	private:
		~Serializer();
		Serializer();
		Serializer(Serializer const& src);
		Serializer& operator=(Serializer const& rhs);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif