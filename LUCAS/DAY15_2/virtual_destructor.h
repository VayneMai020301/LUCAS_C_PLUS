#pragma once
#include <iostream>
using namespace std;
#include <vector>
class House {
public:
	House() {
		cout << "Calling House Constructor ..." << endl;
	}
	~House() {
		cout << "Calling House Destructor ..." << endl;
	}
};
class Base {
public:
	Base() {
		cout << "Calling Base Constructor ..." << endl;
	}
	virtual ~Base() {
		cout << "Calling Base Destructor ..." << endl;
	}
};

class Derived : public Base {
public:
	Derived() {
		cout << "Calling Derived Constructor ..." << endl;
		house = new House();
	}

	~Derived() override {
		cout << "Calling Derived Destructor ..." << endl;
		delete house;
	}
private:
	House* house;
};
class Derived1 : public Base {
public:
	Derived1() {
		cout << "Calling Derived Constructor ..." << endl;
		house = new House();
	}

	~Derived1() override {
		cout << "Calling Derived Destructor ..." << endl;
		delete house;
	}
private:
	House* house;
};

class captute_this {
private:
	int value = 0;

public:
	void ex() {
		auto lamda_change_value = [this]()-> void {
			value += 10;
			};
		lamda_change_value();


		cout << "Gia tri cua value la: " <<value<< endl;
	}
};
class virtual_destructor {

public:
	void run() {
		cout << "-----------------------------------------" << endl;
		Base* obj = new Derived();
		delete obj;

		cout << "-----------------------------------------" << endl;
		Base* obj1 = new Derived1();
		delete obj1;

		/*
		Capture list [&] [=], [this], []
		*/
		{
			captute_this cap;
			cap.ex();
		}
		{/*Capture &*/
			std::vector<int> vt{ 1, 2, 3, 4 };
			auto lambda_change_vector = [&]() {
				vt[1] = 1000;
				};
			lambda_change_vector();

			cout << "gia tri tai vi tri thu 2 la: " << vt[1] << endl;
		}
		{
			/* Capture [=]*/
			std::vector<int> vt{ 1, 2, 3, 4 };
			auto lambda_change_vector = [=]() {
				int value_2 = vt[1];
				cout << "gia tri tai vi tri thu 2 la: " << value_2 << endl;
				};
			lambda_change_vector();

			cout << "gia tri tai vi tri thu 2 la: " << vt[1] << endl;
		}
		{
			/* Capture []*/
			std::vector<int> vt{ 1, 2, 3, 4 };
			auto lambda_change_vector = [](std::vector<int>& temp) {
				temp[1] = 2000;
				};
			lambda_change_vector(vt);

			cout << "gia tri tai vi tri thu 2 la: " << vt[1] << endl;

			std::vector<int> vt1{ 1, 2, 3, 4 };
			auto lambda_change_vector1 = [](std::vector<int> temp) {
				temp[1] = 2000;
				};
			lambda_change_vector1(vt1);

			cout << "gia tri tai vi tri thu 2 la: " << vt1[1] << endl;
		}
	};
};



