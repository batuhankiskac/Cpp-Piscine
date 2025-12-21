#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
	Data data;
	data.x = 10;

	uintptr_t raw = Serializer::serialize(&data);
	Data* deserializedData = Serializer::deserialize(raw);

	std::cout << "Original Data x: " << data.x << std::endl;
	std::cout << "Serialized raw value: " << raw << std::endl;
	std::cout << "Deserialized Data x: " << deserializedData->x << std::endl;

	return 0;
}
