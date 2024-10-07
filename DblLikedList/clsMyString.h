#pragma once

#include<iostream>; 
#include<string>; 
#include <stack>

using namespace std; 

template <class T> 

class clsMyString
{
   private: 

       stack <T>  _Undo;
       stack <T>   _Redo;

   public:

    


       void SetValue(T Value) {

           _Undo.push(Value);
       }

       T GetValue() {

           return _Undo.top();
       }

       _declspec(property(put = SetValue, get = GetValue)) T Value;

       //Undo Funcation 

       void Undo() {

           if (!_Undo.empty()) {

             _Redo.push(GetValue());
             _Undo.pop(); 
              return; 
           }
       }

       // Redo

       void Redo() {

           if (!_Redo.empty()) {

              _Undo.push(_Redo.top());
              _Redo.pop();
               return;
           }

       }

};

