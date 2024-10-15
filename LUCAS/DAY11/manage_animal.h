#pragma once

#include "macro_global.h"

ANIMAL_CLASS(Dog)
ANIMAL_CLASS(Cat)
ANIMAL_CLASS(Bird)
class manage_animal
{
public:
	Dog* create_dog(std::string name, int num_leg);
	Cat* create_cat(std::string name, int num_leg);
	Bird* create_bird(std::string name, int num_leg);
};

