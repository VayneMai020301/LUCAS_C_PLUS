#include "creational_pattern.h"
#include <iostream>

#include "copy_constructor.h"
#include "assignment_operator.h"

#include "define_macro.h"
#include <string>

using namespace std;

void change_data(copy_constructor other){
	other.setData(1000);
}

void change_data_dynamic(copy_constructor* other) {
	other->setData(1000);
}

copy_constructor create_object_dynamic(int _data) {
	copy_constructor* temp = new  copy_constructor(_data);

	return *temp;
}
copy_constructor create_object(int _data) {
	copy_constructor temp(_data);
	return temp;
}

void creational_pattern::run()
{
	cout << " ----------------------------- COPY CONSTRUCTOR -----------------------------" << endl;

	{
		/* Mot doi tuong khoi tao dua tren gia tri cua 1 doi tuong da co san (cung class) */
		copy_constructor A(100);
		copy_constructor B(A);

		COUT("Gia tri data cua B:", B.getData());
		A.setData(3000);
		COUT("Gia tri data cua B:", B.getData());

		COUT("Dia chi cua A: ", &A);
		COUT("Dia chi cua B: ", &B);

		/* No la thamm so duoi dang gia tri truyen vao trong ham  */
		change_data(A);
		change_data(B);
		COUT("Gia tri data cua A: ", A.getData());
		COUT("Gia tri data cua B: ", B.getData());

		/* La gia tri tra ve cua mot ham duoi dang gia tri (cap phat tinh)*/
		copy_constructor rt = create_object(3000);
		COUT("Gia tri data cua rt: ", rt.getData());
	}

	{
		/* Sao chep truc tiep */
		copy_constructor* dynamic1 = new copy_constructor(20);
		copy_constructor* dynamic2 = new copy_constructor(*dynamic1);

		/* Tham so truyen vao ham duoi dang gia tri*/
		change_data_dynamic(dynamic1); 
		change_data_dynamic(dynamic2);

		/* Gia tri tra ve cua ham */
		copy_constructor rt = create_object_dynamic(301);
	}
	

	cout << " ----------------------------- ASSIGNMENT OPERATOR  -----------------------------" << endl;
	{	/* Static Allocation */
		assignment_operator_static ass1(100);
		assignment_operator_static ass2(200);

		ass1 = ass2;
		ass1 = ass1;
		COUT("Gia tri data cua ass1 truoc khi thay doi: ", ass1.getData());
		ass2.setData(30000);
		COUT("Gia tri data cua ass1 sau khi thay doi: ", ass1.getData());

		COUT("Dia chi cua ass1: ", &ass1);
		COUT("Dia chi cua ass2: ", &ass2);

	}

	{ /* Dynamic Allocation */

		assignment_operator_dynamic* dynamic1 = new assignment_operator_dynamic(100);
		assignment_operator_dynamic* dynamic2 = new assignment_operator_dynamic(200);

		*dynamic1 = *dynamic2;
		COUT("Gia tri data cua dynamic1: ", *(dynamic1->getData()));
		COUT("Gia tri data cua dynamic2: ", *(dynamic2->getData()));

		dynamic2->setData(400);

		COUT("Gia tri data cua dynamic1: ", *(dynamic1->getData()));
		COUT("Gia tri data cua dynamic2: ", *(dynamic2->getData()));

		delete dynamic1;
		dynamic1 = nullptr;

		delete dynamic2;
		dynamic2 = nullptr;
	}
}
