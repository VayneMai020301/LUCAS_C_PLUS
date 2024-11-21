#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;
enum class TYPE {
	PHONE, 
	COMPUTER,
	TELEVISION
};
class factorymethod_pattern
{
public:
	void run();
};


/* 1. Thanh phan Product trong Factory Method Pattern (Product Interface)*/
class Device {
public:
	virtual std::string operation() const = 0;
	virtual TYPE getType() const = 0;
private:
	std::string name;
};

/* 2. Thanh phan ConcreteProduct trong Factory Method Pattern */
class Phone : public Device {
public:
	std::string operation() const override {
		cout << "Phone calling operation method" << endl;
		return "This is Phone product" ;
	}

	TYPE getType() const override {
		return TYPE::PHONE;
	}
};

class Computer : public Device {
public:
	std::string operation() const override {
		cout << "Computer calling operation method" << endl;
		return "This is Computer product";
	}
	TYPE getType() const override {
		return TYPE::COMPUTER;
	}
};

class Television : public Device {
public:
	std::string operation() const override {
		cout << "Televison calling operation method" << endl;
		return "This is Televison product";
	}
	TYPE getType() const override {
		return TYPE::TELEVISION;
	}
};

/* 3. Thanh phan Creator trong Factory Method Pattern */
class Creator {
public:
	virtual std::unique_ptr<Device> factoryMemthod() const = 0;

	std::unique_ptr<Device> someOperation()const {
		std::unique_ptr<Device> device = this->factoryMemthod();
		return device;
	};
};



/* 4. Thanh phan ConcreteCretor trong Factory Method Pattern 
	+ PhoneCreator
	+ ComputerCreator
*/
class PhoneCreator : public Creator {
	std::unique_ptr<Device> factoryMemthod() const override {
		cout << "Creating Phone ..." << endl;
		return std::make_unique<Phone>();
	};
};


class ComputerCreator : public Creator {
	std::unique_ptr<Device> factoryMemthod() const override {
		cout << "Creating Computer ..." << endl;
		return std::make_unique<Computer>();
	};
};

class TelevisionCreator: public Creator{
	std::unique_ptr<Device> factoryMemthod() const override {
		cout << "Creating Television ..." << endl;
		return std::make_unique<Television>();
	};
};

/* Client trong Factory Method Pattern */
inline void ClientCode(const Creator& creator) {
	cout << "\nClient not aware creator's class, but it's still working" << endl;
	std::unique_ptr<Device> device = creator.someOperation();
	TYPE type = device->getType();

	//std::unique_ptr<Phone> phone = dynamic_cast<Phone*>(device.release());
	
	//device->operation();
}
