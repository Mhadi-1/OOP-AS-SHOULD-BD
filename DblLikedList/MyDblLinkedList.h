#pragma once
#include<iostream>
#include<string>
using namespace std; 



   template<class T >
	class ClsDblLinkedList
	{

	private:

		int  _LinkedListSize = 0 ;

	public:

		class Node
		{

		public:
			T Data;
			Node* Next;
			Node* Prev;

		};

		Node* Head = NULL;

		void  InseartAtBeginnig(T Value)
		{
			Node* New_Node = new Node();
			New_Node->Data = Value;
			New_Node->Prev = NULL;
			New_Node->Next = Head;

			if (Head != NULL)
			{
				Head->Prev = New_Node;

			}
			Head = New_Node;
			(_LinkedListSize)++;

		};

		void  PrintNode()
		{
			Node* CurrentNode = Head;

			if (CurrentNode == NULL)
			{
				return;
			}

			while (CurrentNode != NULL)
			{
				cout << CurrentNode->Data << " ";
				CurrentNode = CurrentNode->Next;
			}
			cout << endl;
			return;
		};

		void static PrintNode(Node* Head)
		{
			Node* CurrentNode = Head;

			if (CurrentNode == NULL)
			{
				return;
			}

			while (CurrentNode != NULL)
			{
				cout << CurrentNode->Data << " ";
				CurrentNode = CurrentNode->Next;
			}
			cout << endl;
			return;
		}

		Node* Find(T Value)
		{
			Node* CurrentNode = Head;
			if (CurrentNode == NULL)
			{
				return  NULL;
			}
			while (CurrentNode != NULL)
			{
				if (CurrentNode->Data == Value)
					return CurrentNode;
				else
				{
					CurrentNode = CurrentNode->Next;
				}
			}
		}

		void InsertAfter(Node*& CurrentNode, T Value)
		{
			Node* New_Node = new Node();
			New_Node->Data = Value;
			New_Node->Next = CurrentNode->Next;
			New_Node->Prev = CurrentNode;
			if (CurrentNode->Next != NULL)
			{
				CurrentNode->Next->Prev = New_Node;
			}
			CurrentNode->Next = New_Node;
			(_LinkedListSize)++;
		}

		void InsertAtEnd(T Value)
		{
			Node* Cuurent = Head;
			Node* New_Node = new Node();
			New_Node->Data = Value;
			New_Node->Next = NULL;

			if (Head == NULL)
			{
				New_Node->Prev = NULL;
				Head = New_Node;
			}
			else
			{
			  while (Cuurent->Next != NULL) {

			  	Cuurent = Cuurent->Next;
			  }
			  New_Node->Prev = Cuurent;
			  Cuurent->Next = New_Node;
			}

			
			
			(_LinkedListSize++);
		}

		void DeleteNode(Node*& NodeToDelete)
		{
			if (Head == NULL || NodeToDelete == NULL) {
				return;
			}


			if (NodeToDelete->Next != NULL) {

				NodeToDelete->Next->Prev = NodeToDelete->Prev;

			}
			if (NodeToDelete->Prev != NULL) {

				NodeToDelete->Prev->Next = NodeToDelete->Next;
			}
			delete NodeToDelete;
			(_LinkedListSize)--;
		}

		void DeleteFristNode()
		{

			if (Head == NULL)
			{
				return;
			}

			Node* temp = Head;
			Head = Head->Next;
			if (Head != NULL)
			{
				Head->Prev = NULL;
			}
			delete temp;
			(_LinkedListSize)--;
		}

		void DeleteLastNode()
		{
			Node* Current = Head;

			if (Head == NULL) {

				return;
			}
			if (Head->Next == NULL)
			{
				delete Head;
				Head = NULL;
			}

			while (Current->Next->Next != NULL)
			{
				Current = Current->Next;
			}
			Node* Temp = Current->Next;
			Current->Next = NULL;
			delete Temp;
			(_LinkedListSize)--;

		}

		T Size()
		{
			return (_LinkedListSize);
		}

		bool IsEmpty()
		{
			return (Size() == 0);
		}

		void Clear()
		{

			while (_LinkedListSize > 0) {
				DeleteFristNode();
			}
		}


		void GetLastNode(Node*& LatsNode)
		{
			if (Head == NULL)
			{
				return;
			}

			Node* CurrentNode = Head;
			while (CurrentNode->Next->Next != NULL)
			{
				CurrentNode = CurrentNode->Next;
			}
			LatsNode = CurrentNode->Next;
		}


		// 1- Reserve Function  , 2 - front  - last 
		void Reserve()
		{

			Node* Temp = nullptr;
			Node* Current = new Node();
			Current = Head;

			while (Current != nullptr)
			{
				Temp = Current->Prev;
				Current->Prev = Current->Next;
				Current->Next = Temp;
				Current = Current->Prev;
			}

			if (Temp != nullptr) {
				Head = Temp->Prev;
			}


		}
		Node* GetInedx(T Indext)
		{
			T Counter = 0; 
			Node* Current = Head; 

			if (Indext == 0)
				return Current;
			if (Indext < 0 || Head == NULL || Indext > _LinkedListSize )
				return NULL;
			while (Counter < Indext)
			{
				Current = Current->Next; 
				Counter++;
			}
			return Current; 
		}

		int GetIteam(T Iteam)
		{
			Node* Current = GetInedx(Iteam);
			return (Current != NULL) ? Current->Data : NULL;;
		}

		bool UpdateIteam(T Iteam, T NewValue)
		{
			Node* IteamNode = GetInedx(Iteam); 
			if (IteamNode != NULL) {
			    
				IteamNode->Data = NewValue;
				return true ; 

			}  
			return false;
		}

		void InsertAfter(T Index, T value)
		{
			Node* IndexNode = GetInedx(Index); 
			if (IndexNode != NULL)
			{
				InsertAfter(IndexNode, value); 
			}
			 
		}

	};
