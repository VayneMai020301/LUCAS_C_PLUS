#pragma once
#include <iostream>
using namespace std;
class copy_constructor
{
public:
	copy_constructor(int _data) : data (_data) {
		cout << "Calling Constructor ..." << endl;
	}
	~copy_constructor() {
		cout << "Calling Destrcutor ..." << endl;
	}

	/* copy constructor */
	copy_constructor(const copy_constructor& other) {
		data = other.data;
		cout << "calling copy constructor ..." << endl;
	}

	/* Delete Copy Constructor */
	//copy_constructor(const copy_constructor& other) = delete;

	int getData() const { return  data; };

	void setData(const int _data) {
		data = _data;
	}
	
private:
	int data;
};

