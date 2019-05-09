#pragma once
#ifndef SEQUENTIAL_STACK_H
#define SEQUENTIAL_STACK_H

const int Max_size = 100;

template <typename T>
class SeqStack
{
public:
	SeqStack();
	~SeqStack();
	void Push(T x); //push stakc
	T Pop(); //pop stack
	T GetTop(); //get stack top value
	int Empty(); // determine whether empty stack

private:
	int top;
	T data[Max_size];
};

#endif

template<typename T>
inline SeqStack<T>::SeqStack()
{
	top = -1;
}

template<typename T>
inline SeqStack<T>::~SeqStack()
{
}

template<typename T>
inline void SeqStack<T>::Push(T x)
{
	if (top == Max_size - 1)throw "overflow";
	data[++top] = x;
}

template<typename T>
inline T SeqStack<T>::Pop()
{
	if (top == -1)throw"underflow";
	T x = data[top--];
	return x;
}

template<typename T>
inline T SeqStack<T>::GetTop()
{
	if (top != -1)return data[top];
}

template<typename T>
inline int SeqStack<T>::Empty()
{
	if (top == -1)
	{
		return 1;
	} 
	else
	{
		return 0;
	}
}







