#pragma once
#include <iostream>
#include <string>
// Reusablicty : 
#include "MyQueue.h"

using namespace std; 

template <class T > 

class ClsStack : public MyClsQueue<T>
{

private: 

protected : 



public: 

	void push(T Value )
	{
		
		MyClsQueue<T>:: _MyList.InseartAtBeginnig(Value);
		
	}
	void pop()
	{
		MyClsQueue<T>::pop();
	}
	void Print()
	{
		MyClsQueue<T>::Print();
	}
	T top()
	{
		return MyClsQueue<T>::GetIteam(0);
	}
	T back()
	{
		
		return MyClsQueue<T>::GetIteam(MyClsQueue<T>::Size()-1);
	}

	void swap(ClsStack<T>& Stack2)
	{
		ClsStack<T> Temp; 
		Temp = *this;
		*this = Stack2;
		Stack2 = Temp;
	}

};