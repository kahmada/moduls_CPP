#include "Serializer.hpp"

Serializer::Serializer() {

}
Serializer::Serializer(const Serializer&) {

}
Serializer& Serializer::operator=(const Serializer &) { 
    return *this; 
}
Serializer::~Serializer() {

}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
//Le type uintptr_t est un entier non signé capable de contenir 
//une adresse mémoire (en d'autres termes, il peut stocker la valeur d'un pointeur sous forme d'entier).
//La fonction utilise reinterpret_cast pour interpréter le pointeur ptr comme un entier de type uintptr_t.