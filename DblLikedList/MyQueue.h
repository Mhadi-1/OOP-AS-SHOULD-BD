#pragma once
#include<iostream>
#include<string>
#include "MyDblLinkedList.h"

using namespace std; 

template<class T > 

class MyClsQueue

{
	
private:

protected : 
	T _Size = 0; 
	ClsDblLinkedList<T> _MyList; 

public:

	void Push(T iteam)
	{
		
		_MyList.InsertAtEnd(iteam); 

	}

	void Print()
	{
		_MyList.PrintNode();
		
	}

	int Size()
	{
		_Size =  _MyList.Size();;
		return _Size; 
	}

	int front()
	{
		return _MyList.GetIteam(0);;
	}

	int back()
	{
		return _MyList.GetIteam(_Size-1);
	}

	void pop()
	{
		_MyList.DeleteFristNode();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();;
	}

	//Extension #1
	T GetIteam(T Iteam)
	{
		return _MyList.GetIteam(Iteam);
	}
	//Extension #2
	void Reverce()
	{
		_MyList.Reserve();
	}
	//Extension #3
	void UpdateIteam(T Index, T NewValue)
	{
		_MyList.UpdateIteam(Index, NewValue); 
	}
	//Extension #4
	void InsertAfter(T Index, T Value)
	{
		_MyList.InsertAfter(Index, Value); 
	}
	//Extension #5
	void InsertAtFrond(T Value)
	{
		_MyList.InseartAtBeginnig(Value); 
	}
	//Extension #6
	void InserAtBack(T Value )
	{
		_MyList.InsertAtEnd(Value);
	}
	//Extension #7
	void Clear()
	{
		_MyList.Clear();
	}
}; 
