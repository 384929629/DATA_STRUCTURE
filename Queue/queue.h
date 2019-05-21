#pragma once
#ifndef QUEUE_H
#define QUEUE_H

const int QueueSize = 100;

template<typename T>
class CirQueue
{
public:
	CirQueue();
	~CirQueue();
	void EnQueue(T x);
	T DeQueue();
	T GetQueue();
	int Empty();

private:
	T data[QueueSize];
	int front, rear;
};
#endif

template<typename T>
inline CirQueue<T>::CirQueue()
{
	front = rear = QueueSize - 1;
}

template<typename T>
inline CirQueue<T>::~CirQueue()
{
}

template<typename T>
inline void CirQueue<T>::EnQueue(T x)
{
	if ((rear + 1) % QueueSize == front)throw"overflow";
	rear = (rear + 1) % QueueSize;
	data[rear] = x;
}

template<typename T>
inline T CirQueue<T>::DeQueue()
{
	if (rear == front)throw"underflow";
	front = (front + 1) % QueueSize;
	return data[front];
}

template<typename T>
inline T CirQueue<T>::GetQueue()
{
	int i;
	if (rear == front) throw"underflow";
	i = (front + 1) % QueueSize;
	return data[i];
}

template<typename T>
inline int CirQueue<T>::Empty()
{
	/* { front == rear ? return 1 : return 0; }*/
	if(front == rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}




