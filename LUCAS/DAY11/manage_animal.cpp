#include "manage_animal.h"

Dog* manage_animal::create_dog(std::string name, int num_leg)
{
	return new Dog(name, num_leg);
}

Cat* manage_animal::create_cat(std::string name, int num_leg)
{
	return new Cat(name, num_leg);;
}

Bird* manage_animal::create_bird(std::string name, int num_leg)
{
	return new Bird(name, num_leg);;
}

Cat* create_cat(std::string name, int num_leg)
{
	return nullptr;
}

Bird* create_bird(std::string name, int num_leg)
{
	return nullptr;
}
