#include "Serializer.hpp"

int main(void)
{

	Data *data = new Data;
	data->name = "Peter";
	data->age = 42;
	data->score = 87;
    data->pass = true;

	uintptr_t raw = Serializer::serialize(data);
	Data *data_back = Serializer::deserialize(raw);

	std::cout << data_back->name << std::endl;
	std::cout << data_back->age << std::endl;
	std::cout << data_back->score << std::endl;
    std::cout << data_back->pass << std::endl;

	delete data;
	return (0);
}