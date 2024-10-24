#include "data_stack.h"

data_stack::data_stack()
{
}

data_stack::~data_stack()
{
}

data_stack::data_stack(const data_stack& other)
{
}

void data_stack::run()
{
	cout << " ------------------------ Stack Example ------------------------" << endl;
	{
		// cap phat tinh 

		// Day du lieu vao stack 
		std::stack<Image1*> stack;
		stack.push(new Image1(100));
		stack.push(new Image1(200));
		stack.push(new Image1(300));

		// xem du lieu voi phan tu tren cung
		Image1* temp = stack.top();
		cout << "Gia tri cua w trong temp la: " << temp->w << endl;

		// Xoa du lieu
		while (!stack.empty())
		{
			Image1* temp = stack.top();
			delete temp;
			stack.pop();
		}
		if (stack.empty()) {
			cout << "Stack rong ... " << endl;
		}
	}

	{
		// cap phat dong 
		// cap phat tinh 

		// Day du lieu vao stack 
		std::stack<Image1*> *stack = new std::stack<Image1*>;
		stack->push(new Image1(100));
		stack->push(new Image1(200));
		stack->push(new Image1(300));

		// xem du lieu voi phan tu tren cung
		Image1* temp = stack->top();
		cout << "Gia tri cua w trong temp la: " << temp->w << endl;

		// Xoa du lieu
		while (!stack->empty())
		{
			Image1* temp = stack->top();
			delete temp;
			stack->pop();
		}
		if (stack->empty()) {
			cout << "Stack rong ... " << endl;
		}

		delete stack;
	}
}
