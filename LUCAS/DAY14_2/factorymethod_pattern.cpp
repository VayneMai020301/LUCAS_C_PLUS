#include "factorymethod_pattern.h"

void factorymethod_pattern::run()
{
	PhoneCreator phoneCreator;
	ClientCode(phoneCreator);

	ComputerCreator computerCreator;
	ClientCode(computerCreator);

	TelevisionCreator televisonCreator;
	ClientCode(televisonCreator);

	/*for (auto const& iter : deviceVector) {
		iter->operation();
		TYPE type = iter->getType();
		switch (type)
		{
			case TYPE::PHONE:
				cout << "Phone object" << endl;
				break;
			case TYPE::COMPUTER:
				cout << "Computer object" << endl;
				break;
			case TYPE::TELEVISION:
				cout << "Television object" << endl;
				break;
			default:
				break;
		}
	}*/

	

}
