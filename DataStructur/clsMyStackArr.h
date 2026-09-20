#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsDynamicArray.h"
#include "clsMyQueueArr.h"
using namespace std;


template <typename T> class clsMyStackArr:public  clsMyQueueArr<T>
{
protected:




public:

	void push(T Value)
	{
		clsMyQueueArr<T>::_MyList.InsertAtBeginning(Value);
	}

	T Top()
	{
		return clsMyQueueArr<T>::_MyList.Front();
	}
	T Botton()
	{
		return clsMyQueueArr<T>::_MyList.Back();
	}

};

