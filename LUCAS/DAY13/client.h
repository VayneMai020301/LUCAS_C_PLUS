#pragma once
#include "define.h"
#include "singleton_pattern.h"
class client
{
public:
	singleton_pattern* create_sgl(std::string _name) {
		singleton_pattern* sgl = singleton_pattern::getInstance(_name);
		return sgl;
	}
};

