#include "../include/Serializer.hpp"

int main() {
	Data *data = new Data;
	Data *data2;
	uintptr_t raw;

	data->str = "Up";
	data->num = 42;
	data->ch = 'J';
	data->fl = 42.42f;
	data->dbl = 42.42;
	
	raw = Serializer::serialize(data);
	
	data2 = Serializer::deserialize(raw);
	
	std::cout << "Original pointer: " << data << std::endl;
	std::cout << "Serial representation: " << raw << std::endl;
	std::cout << "Deserialized pointer: " << data2 << std::endl;
	
	std::cout << data2->str << std::endl;
	std::cout << data2->num << std::endl;
	std::cout << data2->ch << std::endl;
	std::cout << data2->fl << 'f' << std::endl;
	std::cout << data2->dbl << std::endl;
	

	if (data == data2)
	{
		std::cout << "Success: Pointers match!" << std::endl;
	}

	delete data;
	return 0;
}