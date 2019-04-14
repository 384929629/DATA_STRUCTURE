#pragma once
#ifndef SEQUENTIAL_LIST_H
#define SEQUENTIAL_LIST_H

/***********************************
@author		:ZIYUSONG              *
@data		:2019-04-13            *
@note		:sequence list         *
@API		:as follows			   *
***********************************/

#include <iostream>
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
	int Locate(DataType x);	//find the value,return serial number
	void Insert(int i, DataType x);	//x value is inserted at ith 
	DataType Delete(int i);	//delete ith element
	void PrintList();	//traversal

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

#endif