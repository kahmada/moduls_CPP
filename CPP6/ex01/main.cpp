#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.id = 42;

    uintptr_t raw = Serializer::serialize(&data);

    Data* deserialized = Serializer::deserialize(raw);
    if (deserialized == &data) {
        std::cout << "Serialization and deserialization are successful!" << std::endl;
        std::cout << "Data ID: " << deserialized->id << std::endl;
    } else {
        std::cerr << "Error: Pointers do not match!" << std::endl;
    }

    return 0;
}
