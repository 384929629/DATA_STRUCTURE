#pragma once
#ifndef SEQUENTIAL_LIST_H
#define SEQUENTIAL_LIST_H

/***********************************
@author		:ZIYUSONG              *
@data		:2019-05-02            *
@note		:sequence list         *
@API		:as follows			   *
***********************************/

#include <iostream>
#include <algorithm>
using namespace std;

const int maxsize = 100;


template <class DataType>	//Define template class
class SeqList
{
public:
	SeqList() { length = 0; }
	SeqList(DataType a[], int n);
	~SeqList();
	int Length() { return length; }	//seqlist length
	DataType Get(int i);	//find the ith element location
	int Locate(DataType x);	//find the value,return this number
	void Insert(int i, DataType x);	//x value is inserted at ith 
	DataType Delete(int i);	//delete ith element
	void PrintList();	//traversal

public:
	friend SeqList<int> Add(SeqList<int> A, SeqList<int> B);

private:
	DataType data[maxsize];
	int length;
};

template<class DataType>
inline SeqList<DataType>::SeqList(DataType a[], int n)
{
	if (n > maxsize)throw"Parameters of illegal";
	for(int i=0;i<n;i++)
	{
		data[i] = a[i];
	}
	length = n;
}

template<class DataType>
inline SeqList<DataType>::~SeqList(){}

template<class DataType>
inline DataType SeqList<DataType>::Get(int i)
{
	if (i<1 || i>length)throw"Location illegal";
	else return data[i - 1];
}

template<class DataType>
inline int SeqList<DataType>::Locate(DataType x)
{
	for(int i=0;i<length;i++)
	{
		if (data[i] == x)return i + 1;
		return 0;
	}
}

template<class DataType>
inline void SeqList<DataType>::Insert(int i, DataType x)
{
	if (length >= maxsize)throw"overflow";
	if (i<1 || i>length + 1)throw"Location illegal";
	for (int j = length;j >= i;j--)
	data[j] = data[j - 1];
	data[i - 1] = x;
	length++;

}

template<class DataType>
inline DataType SeqList<DataType>::Delete(int i)
{
	if (length == 0)throw"underflow";
	if (i<1 || i>length)throw"Location illegal";
	int x = data[i - 1];
	for(int j=i;j<length;j++)
	data[j - 1] = data[j];
	length--;
	return DataType();
}

template<class DataType>
inline void SeqList<DataType>::PrintList()
{
	for (int i = 0;i < length;i++)
		cout << data[i] << " ";
}

//Subscript zero is the low order
SeqList<int> Add(SeqList<int> A, SeqList<int> B)
{
	if (typeid(A) != typeid(SeqList<int>))throw"type error";

	int flag = 0, i = 0;
	int n = A.length, m = B.length;
	SeqList<int> C;
	while (i < n && i < m)
	{
		C.data[i] = (A.data[i] + B.data[i] + flag) % 10;
		flag = (A.data[i] + B.data[i] + flag) / 10;
		i++;
	}
	for(;i<n;i++)
	{
		C.data[i] = (A.data[i] + flag) % 10;
		flag = (A.data[i] + flag) / 10;
	}
	for(;i<m;i++)
	{
		C.data[i] = (B.data[i] + flag) % 10;
		flag = (B.data[i] + flag) / 10;
	}
	C.length = max(m, n) + flag;
	if (flag == 1)C.data[C.length] = 1;
	return C;
}

#endif