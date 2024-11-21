// DAY13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "singleton_pattern.h"
#include "client.h"
#include <thread>
#include <mutex>

singleton_pattern* singleton_pattern::instance = nullptr;
std::mutex singleton_pattern::mtx;

singleton_pattern* create_sgl(std::string _name) {
    singleton_pattern* sgl =singleton_pattern::getInstance(_name);
    return sgl;
}

void create_sgl2(std::string _name) {
    singleton_pattern* sgl = singleton_pattern::getInstance(_name);
    COUT("Name cua sgl la", sgl->getName());
}
//
//void change_name(singleton_pattern obj, std::string _newname) {
//    obj.setName(_newname);
//}
//
//singleton_pattern create_singleton(std::string _name){
//    return *singleton_pattern::getInstance(_name);
//}


int main()
{
    
    {
        singleton_pattern* sgl4 = create_sgl("aaaaaaaaaaaaaaaaaaaaa");
        /*singleton_pattern* sgl1 = singleton_pattern::getInstance("K");
        singleton_pattern* sgl2 = singleton_pattern::getInstance("C");
        singleton_pattern* sgl3 = singleton_pattern::getInstance("D");
        singleton_pattern* sgl4 = create_sgl("aaaaaaaaaaaaaaaaaaaaa");

        client clt;
        singleton_pattern* sgl5 = clt.create_sgl("bbbbbbbbbbbbbbbbbbbbbbbbbbbb");

        COUT("Name cua sgl1 la", sgl1->getName());
        COUT("Name cua sgl2 la", sgl2->getName());
        COUT("Name cua sgl3 la", sgl3->getName());
        COUT("Name cua sgl5 la", sgl5->getName());

        COUT("Dia chi cua sgl1", sgl1);
        COUT("Dia chi cua sgl2", sgl2);
        COUT("Dia chi cua sgl3", sgl3);
        COUT("Dia chi cua sgl4", sgl4);
        COUT("Dia chi cua sgl5", sgl5);*/
    }
    
    {/* Singlton thread safe*/
        std::thread t1(create_sgl2, "K");
        std::thread t2(create_sgl2, "C");
        std::thread t3(create_sgl2, "D");
        std::thread t4(create_sgl2, "E");

        t1.join();
        t2.join();
        t3.join();
        t4.join();
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
