// DAY11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "macro_global.h"
#include "manage_animal.h"
using namespace std;

int main()
{

    /*  1 dinh nghia hang so*/
    cout << "Gia tri cua PI la: " << PI << endl;


    /* 2. Thay the van ban */
    cout << MSG_ERROR << endl;
    cout << MSG_INFOR << endl;


    /*3. Macro voi tham so (Parameterzed macro )*/
    int x = 100;
    cout << "Gia tri binh phuong cua x: " << SQUARE(x) << endl;

    /*5. Dieu kien bien dich (Conditional Compilation) */
    #ifdef DEBUG
        std::cout << "Debug mode ON" << endl;
    #elif   
        std::cout << "Debug mode OFF" << endl;
    #endif // DEBUG


    /*6. Macro long nhau */
        cout << "Gia tri lon nhat cua 100, 200 la: " << MAX(100, 200) << endl;
        cout << "Gia tri lon nhat cua 100, 200 la: " << MAX4(100, 0,201,-200) << endl;
    

     /*7. Loai bo doan code khong can thiet */
     
    #ifdef ENABLE_FEATURE_1
        int a = 10;
        int b = 10;
        int c = a * b;
        cout << "gia tri cua a*b la: " << c << endl;
    #elif
        cout << "Feature 1 disabled" << endl;
    #endif // ENABLE_FEATURE_1

    #ifdef ENABLE_FEATURE_2
            int a2 = 10;
            int b2 = 10;
            int c2 = a2 * b2;
            cout << "gia tri cua a*b la: " << c2 << endl;
    #elif 
            cout << "Feature 2 disabled" << endl;
    #endif // ENABLE_FEATURE_1

     /* 8. Ket hop ky tu */

            CREATE_VARIABLE(test) = 10;
            cout << "Gia tri cua bien test la: " << var_test << endl;

            CREATE_VARIABLE(train) = 100;
            cout << "Gia tri cua bien train  la: " << var_train << endl;
    /*9. Chuyen token thanh chuoi */

            cout << "Chuoi toi can in ra la: " << TO_STRING(This is tring) << endl;


            /*10. Platform*/

            cout << "Platform: " << OS_NAME << endl;
            /*11. class definition */
            Dog* dog = new Dog("d1", 4);
            dog->showInfo();
    
     /**/

            manage_animal mana;
            Dog* d1 = mana.create_dog("d1", 4);
            d1->showInfo();
            Cat* c1 = mana.create_cat("c1", 4);
            c1->showInfo();
            Bird* b1 = mana.create_bird("b1", 4);
            b1->showInfo();

    /* Dangling Pointer */
            auto show = [=](Dog* d) {
                try
                {
                    if (!d) {
                        LOG_HISTORY("Pointer is null");
                        return;
                    }; /* (!d) = (d!=nullptr) */
                    d->showInfo();
                }
                catch (const std::exception&)
                {
                        
                }
            };
            Dog* d2 = new Dog("d2", 4);
            Dog* d3 = d2;
            delete d2;
            d3 = nullptr;
            show(d3);

            /* Increase */
            int aa = 10;
            INCREASE(aa)

            cout << "Gia tri moi cua bien a: " << aa ;

            int xx = 10;
            cout << xx++ << endl;
            cout << ++xx << endl;

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
