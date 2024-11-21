#pragma once
#include "define.h"

class singleton_pattern
{
public:
	static singleton_pattern* getInstance(std::string _name) {
		std::lock_guard<std::mutex>lock(mtx);
		if (instance == nullptr) {
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
			instance = new singleton_pattern(_name);
		}
		return instance;
	}

	std::string getName()const { return name; };

	void setName(const std::string _name) { name = _name; };
	
private:
	static singleton_pattern* instance;
	static std::mutex mtx;
	std::string name;

	/*private constructor */
	singleton_pattern(std::string _name) : name(_name) {
		COUT("Calling Constructor", "");
	}

	/* Delete Copy Constructor */
	singleton_pattern(const singleton_pattern& other) = delete;

	/* Delete Assignment Operator */
	singleton_pattern operator=(const singleton_pattern& other) = delete;
};


