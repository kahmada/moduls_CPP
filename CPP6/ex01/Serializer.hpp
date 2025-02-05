#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <iostream>
struct Data {
    int id;
    // std::string name;
};

class Serializer {
public:
    static uintptr_t serialize(Data* ptr);

    static Data* deserialize(uintptr_t raw);

private:
    Serializer();
	Serializer(const Serializer &serializer);
	Serializer	&operator=(const Serializer &rhs);
	~Serializer();
};

#endif
