#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "clsDbilLinkedList.h"
#include "clsMyQueue.h"
using namespace std;

template <typename T> class clsDynamicArray
{
protected:
	int _Size;

	T* _TempArr;
public:
	T* Arr;

	clsDynamicArray(int Size)
	{
		if (Size < 0)
			Size = 0;

		_Size = Size;

		Arr = new T[_Size];
	}

	~clsDynamicArray()
	{

		delete[] Arr;
	}

	bool SetItem(int Index, T Value)
	{
		if (Index >= _Size || Index < 0)
		{
			return false;
		}

		Arr[Index] = Value;

		return true;

	}

	T Front()
	{
		return Arr[0];
	}

	T Back()
	{
		return Arr[_Size - 1];
	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	int Size()
	{
		return _Size;
	}

	void PrintArr()
	{
		int i = 0;
		while (i < _Size)
		{
			cout << Arr[i] << "   ";
			i++;
		}
		cout << endl;
	}

	void Resize(int NewSize)
	{
		if (NewSize < 0)
			NewSize = 0;

		_TempArr = new T[NewSize];

		if (NewSize < _Size)
			_Size = NewSize;

		for (int i = 0; i < _Size; i++)
		{
			_TempArr[i] = Arr[i];
		}
		_Size = NewSize;

		delete[] Arr;

		Arr = _TempArr;
	}

	T GetItem(int Index)
	{

		if (Index >= Size || Index < 0)
			return T();
		return Arr[Index];

	}

	void Reverse()
	{
		_TempArr = new T[_Size];
		int Count = 0;
		for (int i = _Size; i >= 0; i--)
		{
			_TempArr[Count] = Arr[i];
			Count++;
		}

		delete[] Arr;
		Arr = _TempArr;

	}

	void Clear()
	{
		delete[] Arr;
		Arr = NULL;
		_Size = 0;
	}

	void DeleteItemAt(int Index)
	{
		if (Index >= _Size || Index < 0)
			return;

		for (int i = Index; i < _Size - 1; i++)
		{
		
			Arr[i] = Arr[i + 1];
		
		}
		
		_Size--;

	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}

	void DeletFirstItem()
	{
		DeleteItemAt(0);
	}
	
	int Find(T Value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (Arr[i] == Value)
			{
				return i;
			}
		}
		return -1;
	}



	bool DeleteItem(T Value)
	{
		int Index = Find(Value);

		if (Index == -1)
		{
			return false;
		}


		DeleteItemAt(Index);
		return true;

	}

	
	bool InsertAt(int Index, T Value)
	{
		if (Index > _Size || Index < 0)
			return;
		_Size++;
		_TempArr = new T[_Size];

		for (int i = 0; i < Index; i++)
		{
			
			_TempArr[i] = Arr[i];
			

		}
		_TempArr[Index] = Value;

		for (int i = Index; i < _Size; i++)
		{
			_TempArr[i + 1] = Arr[i];

		}
		delete[] Arr;
		Arr = _TempArr;
		return true;
	}

	void InsertAtBeginning(T Value)
	{
		InsertAt(0, Value);
	}

	bool InsertBefore(int Index, T Value)
	{
		if (Index < 1)
			return InsertAt(0, Value);
		else
			return InsertAt(Index - 1 , Value);
	}

	bool InsertAfter(int Index, T Value)
	{
		if (Index >= _Size)
			return InsertAt(_Size - 1, Value);
		else
			return InsertAt(Index + 1, Value);
	}

	void InsertAtEnd(T Value)
	{
		InsertAt(_Size, Value);
	}

	void Update(int Index, T Value)
	{
		if (Index > _Size || Index < 0)
			return;

		Arr[Index] = Value;
	}

};

