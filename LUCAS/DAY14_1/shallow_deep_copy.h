#pragma once
#include <iostream>
using namespace std;
class shallow_deep_copy
{
public:
	void run();
};

class ClassData {

private:
	int* data;
	int* data_1;

public:
	ClassData(int _data, int _data1) : data(new int(_data)),data_1 (new int(_data1)) {};

	/* Copy Constructor */
	ClassData(const ClassData& other) {
		cout << "Calling Copy Constructor..." << endl;
		if (this != &other) {
			
			delete data;
			data = new int(*other.data); /* Deep copy */
		}

		/*Shallow Copy data_1*/
		data_1 = other.data_1;
	}

	/* Assignment Operator */
	ClassData& operator = (const ClassData & other){
		cout << "Calling Assignment Operator" << endl;
		data = other.data; /* Shallow Copy* /

		/* Deep Copy Cho data_1 */
		if (this != &other) {
			delete data_1;
			data_1 = new int(*other.data_1); /* Deep copy */
		}
		return *this;
	}

	/* show Data */
	void showData() const {
		cout << "Gia tri cua data la: " << *data << endl;
		cout << "Gia tri cua data_1 la: " << *data_1 << endl;
	}

	void setData(const int _value, const int _value1) {
		*data = _value;
		*data_1 = _value1;
	}
};



