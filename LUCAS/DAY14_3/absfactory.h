#pragma once
#include <iostream>
using namespace std;


class absfactory
{
public:
	void run();
};

/* Abstract Product */
class Button {
public:
	virtual void paint() const = 0;
};

class CheckBox {
public:
	virtual void paint() const = 0;
};

class ComBox {
public:
	virtual void paint() const = 0;
};

/* 4. Concrete Product (Trien khai san cu the cua 1 ho)*/

class WinButton : public Button {
public:
	void paint() const override {
		std::cout << "Render Button in windows " << endl;
	}
};

class WinCheckBox : public CheckBox {
public:
	void paint() const override {
		std::cout << "Render CheckBox in windows " << endl;
	}
};

class WinComboBox : public ComBox {
public:
	void paint() const override {
		std::cout << "Render ComboBox in windows " << endl;
	}
};

class MacButton : public Button {
public:
	void paint() const override {
		std::cout << "Render Button in MacOS " << endl;
	}
};

class MacCheckBox : public CheckBox {
public:
	void paint() const override {
		std::cout << "Render CheckBox in MacOS " << endl;
	}
};

class MacComboBox : public ComBox {
public:
	void paint() const override {
		std::cout << "Render ComboBox in MacOS " << endl;
	}
};

class LinuxButton : public Button {
public:
	void paint() const override {
		std::cout << "Render Button in Linux " << endl;
	}
};

class LinuxCheckBox : public CheckBox {
public:
	void paint() const override {
		std::cout << "Render CheckBox in Linux " << endl;
	}
};

class LinuxComboBox : public ComBox {
public:
	void paint() const override {
		std::cout << "Render ComboBox in Linux " << endl;
	}
};

/* 1. Abstract Factory (Tao ra san pham thuoc cung 1 ho)*/

class GUIFactory {
public:
	virtual std::unique_ptr<Button> createButton()const = 0;
	virtual std::unique_ptr<CheckBox> createCheckBox()const = 0;
	virtual std::unique_ptr<ComBox> createComboBox()const = 0;
};

/* 2. Concrete Factory */
class WinFactory : public GUIFactory {

public:
	std::unique_ptr<Button> createButton() const override {
		return std::make_unique<WinButton>();
	};
	std::unique_ptr<CheckBox> createCheckBox() const override {
		return std::make_unique<WinCheckBox>();
	};

	std::unique_ptr<ComBox> createComboBox() const override {
		return std::make_unique<WinComboBox>();
	};
};

class MacFactory : public GUIFactory {
public:
	std::unique_ptr<Button> createButton() const override {
		return std::make_unique<MacButton>();
	};
	std::unique_ptr<CheckBox> createCheckBox() const override {
		return std::make_unique<MacCheckBox>();
	};
	std::unique_ptr<ComBox> createComboBox() const override {
		return std::make_unique<MacComboBox>();
	};
};

class LinuxFactory : public GUIFactory {
public:
	std::unique_ptr<Button> createButton() const override {
		return std::make_unique<LinuxButton>();
	};
	std::unique_ptr<CheckBox> createCheckBox() const override {
		return std::make_unique<LinuxCheckBox>();
	};
	std::unique_ptr<ComBox> createComboBox() const override {
		return std::make_unique<LinuxComboBox>();
	};
};

/* Client */
inline void client(const GUIFactory& factory, std::string object_name ="", std::string os_na="") {
	//{
	//	WinFactory winfactory;
	//	if ((object_name == "button")) {
	//		if (os_name == "window") {
	//			winfactory.createButton();
	//		}
	//	}
	//	
	//	if ((object_name == "checkbox")) {
	//		if (os_name == "window") {

	//		}
	//	}

	//	if ((object_name == "combobox")) {
	//		if (os_name == "window") {

	//		}
	//	}
	//}
	//

	auto button		= factory.createButton();
	auto checkbox	= factory.createCheckBox();
	auto comboBox	= factory.createComboBox();

	button->paint();
	checkbox->paint();
	comboBox->paint();
}

