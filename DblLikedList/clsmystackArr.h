#pragma once
#include<iostream>
#include<string>
#include"clsmyQueueArr.h"

using namespace std; 

template <class T>
class clsmystackArr : public clsmyQueue <T>
{
  private:
  
  public:

	  void push(T Value) {
		  
		  clsmyQueue<T>::InsertAtFrond(Value);
	  }
	  T top() {

		  return clsmyQueue<T>::front();
	  }
	  

};

