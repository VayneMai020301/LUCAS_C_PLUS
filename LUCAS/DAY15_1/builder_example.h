#pragma once
#include <iostream>
using namespace std;

class builder_example
{
public:
	void run();
};

/* Thanh phan 1 Product */
class House {
public:
	std::string walls;
	std::string roof;
	std::string windows;
	std::string chair;
	void show() {
		cout << "House with " << walls << " walls, " << roof << " roof, " << windows << " windows, " << chair << " chair" << endl;
 	}
};

/* Thanh phan 2  Builder (Interface) khai bao nhung phuong thuc can thiet de xay dung duoc doi tuong Product */

class Builder {

public:
	virtual ~Builder() = default;

	/* Outside Construction */
	virtual void buildWalls() = 0;
	virtual void buildRoof() = 0;
	virtual void buildWindows() = 0;

	/* Inside Construction */
	virtual void buildChair() = 0;

	/* Return House */
	virtual House* getHouse() = 0;
};


/* Thanh phan thu 3 ConcreteBuilder (Dinh nghia lai nhung hanh vi cu the can thiet de xay dung nen thanh phan Product)*/
class ConcreteBuilder : public Builder {
private:
	House* house;
public:
	ConcreteBuilder() {
		house = new House();
	}
	~ConcreteBuilder() {
		delete house;
	}

	void buildWalls() override {
		house->walls = "this walls";
	}
	void buildWindows() override {
		house->windows = "this windows";
	}
	void buildRoof() override {
		house->roof = "this roof";
	}

	void buildChair() override {
		house->chair = "this chair";
	}

	House* getHouse() override {
		return house;
	}
};


/* Thanh phan thu 4 Director, Dieu phoi viec xay dung product (tham so truyen vao ConcreteBuilder)*/
class Director {
private:
	Builder* builder;

public:
	Director(Builder* _builder) :builder(_builder){}

	void constructionHouse_1() {
		builder->buildWalls();
		builder->buildRoof();
		builder->buildWindows();
	}

	void constructionHouse_2() {
		builder->buildWalls();
	}

	void constructionHouse_3() {
		builder->buildChair();
	}
};