#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "clsDynamicArray.h"
using namespace std;


template <typename T> class clsMyQueueArr
{
protected:

	clsDynamicArray <T> _MyList;


public:


	void Push(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	void Pop()
	{
		_MyList.DeletFirstItem();
	}

	void Print()
	{
		_MyList.PrintArr();
	}

	int Size()
	{
		return _MyList.Size();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}


	T Front()
	{
		return _MyList.GetItem(0);
	}

	T Back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	T GetItem(int Index)
	{
		return _MyList.GetItem(Index);
	}

	void Revers()
	{
		_MyList.Reverse();
	}

	void Update(int Index, T Value)
	{
		_MyList.Update(Index, Value);
	}

	bool InsertAfter(int Index, T Value)
	{
		return _MyList.InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value)
	{
		_MyList.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	void Clear()
	{
		_MyList.Clear();
	}


};

