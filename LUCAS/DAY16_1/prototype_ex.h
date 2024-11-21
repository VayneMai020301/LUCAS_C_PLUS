#pragma once
#include <iostream>
using namespace std;

class prototype_ex
{
public:
	void run();
};

class House {
public:
	virtual ~House() = default;
	virtual House* clone() const = 0;
	virtual void show() const = 0;
};

class HouseA : public House {
private:
	std::string name;

public:
	HouseA(std::string name) {
		this->name = name;
	};

	House* clone() const override {
		return new HouseA(*this);
	}

	void show() const override {
		cout << "Name of HouseA: " << name << endl;
	}
	/*~HouseA() {
		cout << "Calling HouseA Destructor ..." << endl;
	}*/
};

class HouseB : public House {
private:
	std::string name;

public:
	HouseB(std::string name) {
		this->name = name;
	};

	House* clone() const override {
		return new HouseB(*this);
	}

	void show() const override {
		cout << "Name of HouseB: " << name << endl;
	}
	/*~HouseB() {
		cout << "Calling HouseB Destructor ..." << endl;
	}*/
};

inline void client(House* housePrototype) {
	House* cloneObject = housePrototype->clone();
	cloneObject->show();

	delete cloneObject;
}


