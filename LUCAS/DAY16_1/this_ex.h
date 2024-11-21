#pragma once
#include <iostream>
using namespace std;

class this_ex
{
public:
	void run();
};

/* Phan biệt biến thành viên và tham số*/

class Person {
private:
	std::string name;
public:
	Person(std::string name) {
		this->name = name;
	}

	void show() {
		cout << "Name: " << name << endl;
	}
};

/* Chuoi goi ham (Method Chaining)*/
class Rectangle {
private:
	int w; 
	int h;
public:
	Rectangle(int _w, int _h) :w(_w), h(_h){}
	
	/* Copy Constructor */
	Rectangle (const Rectangle& other) {
		cout << "Calling Copy Constructor ..." << endl;
	}
	/*void setW(int _w) {
		w = _w;
	}*/
	~Rectangle() {
		cout << "Dia chi: " << this << endl;
	}
	Rectangle& setW(int _w) {
		this->w += _w;
		return *this;
	}
	Rectangle& setH(int _h) {
		this->h += _h;
		return *this;
	}

	void show() {
		cout << "Width: " << w << " - Height: " << h << endl;
	}

	Rectangle& getRectangle() {
		return *this;
	}

	int getW()const { return w; }
	int getH()const { return h; }


	void Compare(Rectangle& rec) {
		if (this->getW() == rec.getW()) {
			cout << "Hai doi tuong giong nhau" << endl;
		}
		else {
			cout << "Hai doi tuong khong giong nhau" << endl;
		}
	}
};




