#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsDbilLinkedList.h"
#include "clsMyQueue.h"
using namespace std;


template <typename T> class clsMyStack:public clsMyQueue<T>
{
protected :

	

public:

	void Push(T Value)
	{
		clsMyQueue<T>::_MyList.InsertAtBeginning(Value);
	}
	T Top()
	{
		return clsMyQueue<T>::_MyList.Front();
	}
	T Botton()
	{
		return clsMyQueue<T>::_MyList.Back();
	}

};

