#pragma once
#include <iostream>
#include "define_macro.h"

class assignment_operator_static
{
public:
	/* Constructor */
	assignment_operator_static(int _data) : data(_data) {
		COUT("Calling Constructor ...", "");
	}

	/* Destructor  */
	~assignment_operator_static() {
		COUT("Calling Destructor  ...", "");
	}

	assignment_operator_static& operator = (assignment_operator_static& other) {
		if (this!= &other) {
			data = other.data;
			COUT("Calling Assignment Operator  ...", "");
		}
		return *this;
	}

	void setData(const int _data) {
		data = _data;
	}

	int getData() const {
		return data;
	}
	void run();
private:
	int data;
};

class assignment_operator_dynamic
{
public:
	/* Constructor */
	assignment_operator_dynamic(int _data) {
		data = new int(_data);
		COUT("Calling Constructor ...", "");
	}

	/* Destructor  */
	~assignment_operator_dynamic() {
		COUT("Calling Destructor  ...", "");
	}

	/* Deep Copy */
	assignment_operator_dynamic& operator = (assignment_operator_dynamic& other) {
		if (this != &other) {
			delete data;
			data = new int(*other.data);
			COUT("Calling Assignment Operator  ...", "");
		}
		return *this;
	}
	//assignment_operator_dynamic& operator = (assignment_operator_dynamic& other) = delete;
	void setData(const int _data) {
		*data = _data;
	}

	int* getData() const {
		return data;
	}
	void run();
private:
	int* data;
};

