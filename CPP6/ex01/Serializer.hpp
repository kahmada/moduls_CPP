#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
struct Data {
    int id;
};

class Serializer {

    private:
        Serializer();
        Serializer(const Serializer &serializer);
        Serializer	&operator=(const Serializer &rhs);
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
