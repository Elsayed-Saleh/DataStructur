#pragma once

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

template<typename T> class clsDbilLinkedList
{
protected:
	int _Size;

public:

	class Node
	{

	public:
		T Value;
		Node* Next;
		Node* Prev;
	};
	
	Node* Head = NULL;
	
	void InsertAtBeginning(T value)
	{

		Node* newNode = new Node();
		newNode->Value = value;
		newNode->Next = Head;
		newNode->Prev = NULL;

		if (Head != NULL) {
			Head->Prev = newNode;
		}
		Head = newNode;
		_Size++;

	}

	void PrintList()
	{
		Node* Current = Head;
		while (Current != NULL)
		{
			cout << Current->Value << endl;
			Current = Current->Next;
		}
		cout << "\n";
	}

	Node* Find(T Value)
	{
		Node* Current = Head;

		while (Current != NULL)
		{
			if (Current->Value == Value)
				return Current;
			Current = Current->Next;
		}

		return NULL;
	
	}

	void InsertAfter(Node* Current, T Value)
	{
		Node* NewNode = new Node();

		NewNode->Value = Value;
		NewNode->Next = Current->Next;
		NewNode->Prev = Current;

		if (Current->Next != NULL)
		{
			Current->Next->Prev = NewNode;
		}
		Current->Next = NewNode;
		_Size++;
	}

	void InsertAtEnd(T Value)
	{
		Node* NewNode = new Node();

		NewNode->Value = Value;
		NewNode->Next = NULL;
		if (Head == NULL)
		{
			NewNode->Prev = NULL;
			Head = NewNode;
		}
		else
		{
			Node* current = Head;
			while (current->Next != NULL) {
				current = current->Next;
			}
			current->Next = NewNode;
			NewNode->Prev = current;
		}
		_Size++;
	}


	void DeleteNode(Node*& NodeToDelete) {

		
		if (Head == NULL || NodeToDelete == NULL) {
			return;
		}
		if (Head == NodeToDelete) {
			Head = NodeToDelete->Next;
		}
		if (NodeToDelete->Next != NULL) {
			NodeToDelete->Next->Prev = NodeToDelete->Prev;
		}
		if (NodeToDelete->Prev != NULL) {
			NodeToDelete->Prev->Next = NodeToDelete->Next;
		}
		delete NodeToDelete;

		_Size--;
	}

	void DeleteFirstNode()
	{

		

		if (Head == NULL) {
			return;
			_Size = 0;
		}
		Node* temp = Head;
		Head = Head->Next;
		if (Head != NULL) {
			Head->Prev = NULL;
		}
		delete temp;
		_Size--;
	}

	void DeleteLastNode() {

		

		if (Head == NULL) {
			return;
			_Size = 0;
		}

		if (Head->Next == NULL) {
			delete Head;
			Head = NULL;
			return;
			_Size = 0;
		}

		Node* current = Head;
		// we need to find the node before last node.
		while (current->Next->Next != NULL)
		{
			current = current->Next;
		}

		Node* temp = current->Next;
		current->Next = NULL;
		delete temp;
		_Size--;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		Node* Current = Head;
		Node* temp = nullptr;

		while (Current != nullptr)
		{
			temp = Current->Prev;
			Current->Prev = Current->Next;
			Current->Next = temp;
			Current = Current->Prev;
		}
		if (temp != nullptr)
		{
			Head = temp->Prev;
		}
	}

	Node* GetNode(int Index)
	{
		int Counter = 0;
		Node* Current = Head;
		if (Index > _Size - 1 || Index < 0)
		{
			return NULL;
		}

		while (Current != NULL && (Current->Next != NULL))
		{
			if (Counter == Index)
			{
				break;
			}
			Current = Current->Next;
			Counter++;
		}


		return Current;

	}

	T GetItem(int Index)
	{
		Node* N = GetNode(Index);
		if (N == NULL)
		{
			return NULL;
		}

		return  N->Value;
	}

	bool Update(T Index, T Value)
	{
		Node* N = GetNode(Index);
		if (N != NULL)
		{
			N->Value = Value;
			return true;
		}
		else
			return false;

	}

	bool InsertAfter(T Index, T Value)
	{
		Node* N = GetNode(Index);
		if (N != NULL)
		{
			InsertAfter(N, Value);
			return true;
		}
		return false;
	}


};

