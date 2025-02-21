#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int main()
{
	Data *ptr = new Data;
	ptr->c = 'P';
	ptr->i = 42;
	ptr->f = 21.f;

	uintptr_t raw = Serializer::serialize(ptr);
	Data *other_ptr = Serializer::deserialize(raw);

	std::cout << "Original data: " << ptr->c << ' ' << ptr->i << ' ' << ptr->f << std::endl;
	std::cout << "Deserialized data: " << other_ptr->c << ' ' << other_ptr->i << ' ' << other_ptr->f << std::endl;

	std::cout << "Serialized value: " << raw << std::endl;
	std::cout << "Original ptr value: " << ptr << std::endl;
	std::cout << "Deserialized ptr value: " << other_ptr << std::endl;

	delete ptr;
}