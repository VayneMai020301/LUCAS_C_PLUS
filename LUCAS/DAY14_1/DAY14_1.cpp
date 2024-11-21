// DAY14_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "shallow_deep_copy.h"

int main()
{
    {
        cout << " ---------------------------- SHALLOW COPY ----------------------------" << endl;

        ClassData obj1(100, 101);
        ClassData obj2 = obj1; /* Copy Constructor */

        obj1.showData();
        obj2.showData();

        obj2.setData(200, 201);
        obj2.showData();

        obj1.showData();
    }

    {
        cout << " ---------------------------- DEEP COPY ----------------------------" << endl;

        ClassData obj1(100, 101);
        ClassData obj3(300, 301);

        obj1 = obj3; /* Assignment Operator */
        obj1.showData();

        obj3.setData(111,222);
        obj3.showData();

        obj1.showData();
    }

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
