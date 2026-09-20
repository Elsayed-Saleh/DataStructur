#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsMyStack.h"
#include <stack>
using namespace std;

class clsMyString
{
protected:
	stack<string>_Undo;
	stack<string>_Redo;

	string _Value;

public:

	void SetValue(string Value)
	{
		_Undo.push(Value);

		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue))string Value;


	void Undo()
	{
		if (!_Undo.empty())
		{
			_Redo.push(_Value);
			_Undo.pop();
			_Value = _Undo.top();
			
		}
	}


	void Redo()
	{
		if (!_Redo.empty())
		{
			_Undo.push(_Value);
			_Value = _Redo.top();
			_Redo.pop();

		}
	}

};

