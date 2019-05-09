#pragma once
#ifndef BOTHSEQUENTIAL_STACK_H
#define BOTHSEQUENTIAL_STACK_H

const int StackSize = 100;

// if i is 1 then stack1,if i is 2 then stack2
template<typename T>
class BothStack
{
public:
	BothStack();
	~BothStack();
	void Push(int i, T x); //push stakc
	T Pop(int i); //pop stack
	T GetTop(int i); //get stack top value
	int Empty(int i); // determine whether empty stack

private:
	T data[StackSize];
	int top1, top2;

};

#endif

template<typename T>
inline BothStack<T>::BothStack()
{
	top1 = -1;
	top2 = StackSize;
}

template<typename T>
inline BothStack<T>::~BothStack()
{
}

template<typename T>
inline void BothStack<T>::Push(int i, T x)
{
	if (top1 == top2 - 1)throw"overflow";
	if (i == 1)data[++top1] = x;
	if (i == 2)data[--top2] = x;
}

template<typename T>
inline T BothStack<T>::Pop(int i)
{
	if(i == 1)
	{
		if (top1 == -1)throw"underflow";
		return data[top1--];
	}
	if(i == 2)
	{
		if (top2 == StackSize)throw"underflow";
		return data[top2++];
	}

}

template<typename T>
inline T BothStack<T>::GetTop(int i)
{
	if(i == 1)
	{
		return data[top1];
	}
	if(i == 2)
	{
		return data[top2];
	}
}

template<typename T>
inline int BothStack<T>::Empty(int i)
{
	if(i == 1)
	{
		if (top1 == -1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(i == 2)
	{
		if (top2 == StackSize)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

}

