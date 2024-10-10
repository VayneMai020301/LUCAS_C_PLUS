#pragma once
#include <iostream>
#include <stack>
#include "Image.h"

using namespace std;

class data_stack
{
public:
	data_stack();
	~data_stack();
	data_stack(const data_stack& other);
	void run();
};

