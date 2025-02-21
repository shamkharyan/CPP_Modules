#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif //SERIALIZER_HPP_