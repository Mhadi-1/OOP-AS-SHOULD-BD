#pragma once

#include <iostream>; 
#include <string>; 
#include "MyDynamicArray.h"
using namespace std; 

template<class T> 

class clsmyQueue 
{

protected: 

	clsDynamicArray<T> _MyList; 

public:

	
	void push(T Value) {
	
		_MyList.InserAtEnd(Value);
	}
	void pop() {

		_MyList.DeleteFristItem();
	}
	T    front()
	{
		return _MyList.GetItem(0);
	}
	T    back() {

		return _MyList.GetItem(Size() - 1);
	}
	void IsEmpty() {

		_MyList.IsEmpty();
	}
	T    Size() {

		return _MyList.Size();
	}
	T    GetIteam(T Index) {

		return _MyList.GetItem(Index);
	}
	void Reverce() {

		_MyList.Reverse();
	}
	bool UpdateIteam(T Index , T NewValue) {

		return _MyList.UpdateIteam(Index, NewValue);
	}
	bool InsertAfter(T Index, T Value) {

		return _MyList.InserAfter(Index, Value);
	}
	bool InsertAtFrond(T Value) {

		return _MyList.InsertAtBeginnging(Value);
	}
	bool InserAtBack(T Value) {
		return _MyList.InserAtEnd(Value);
	}
	void Clear() {

		_MyList.Clear();
	}
	void Print() {

		_MyList.PrintList();
	}

	










};

