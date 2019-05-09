#pragma once
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

/***********************************
@author		:ZIYUSONG              *
@data		:2019-04-14            *
@note		:Singly linked list    *
@API		:as follows			   *
***********************************/

//#include <iostream>
//using namespace std;

template<class DataType>
struct  Node
{
	DataType data;
	Node<DataType> *next;
};

template<class DataType>
class LinkList
{
public:
	LinkList();
	LinkList(DataType a[], int n,bool method);//if method==ture,creatlist_head,else creatlist_tail
	~LinkList();
	int Length();	//list length
	DataType Get(int i);	//find the ith element location
	int Locate(DataType x);	//find the value,return serial number
	void Insert(int i, DataType x);	//x value is inserted at ith 
	DataType Delete(int i);	//delete ith element
	void PrintList();	//traversal

private:
	Node<DataType> *first;
};

#endif

template<class DataType>
inline LinkList<DataType>::LinkList()
{
	first = new Node<DataType>;	//generating header
	first->next = NULL;	//the header pointer field is empty
}

template<class DataType>
inline LinkList<DataType>::LinkList(DataType a[], int n,bool method)
{
	if (method == true)
	{
		first = new Node<DataType>;
		first->next = NULL;	//initialize empty list

		for (int i = 0;i < n;i++)
		{
			Node<DataType> *s = new Node<DataType>;
			s->data = a[i];
			s->next = first->next;
			first->next = s;
		}
	}
	else
	{
		first = new Node<DataType>;
		Node<DataType> *r = first;	//initialize tail pointer
		for(int i=0;i<n;i++)
		{
			Node<DataType> *s = new Node<DataType>;
			s->data = a[i];
			r->next = s;
			r = s;
		}
		r->next = NULL;
	}
}

template<class DataType>
inline LinkList<DataType>::~LinkList()
{
	while (first != NULL)
	{
		Node<DataType> *p = first;
		first = first->next;
		delete p;
	}
}

template<class DataType>
inline int LinkList<DataType>::Length()
{
	Node<DataType>  *p = first->next;
	int count = 0;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}

template<class DataType>
inline DataType LinkList<DataType>::Get(int i)
{
	Node<DataType> *p = first->next;
	int count = 1;
	while (p != NULL && count < i)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)throw"Location";
	else return p->data;
}

template<class DataType>
inline int LinkList<DataType>::Locate(DataType x)
{
	Node<DataType> *p = first->next;
	int count = 1;
	while (p != NULL)
	{
		if (p->data == x)return count;	//return serial number
		p = p->next;
		count++;
	}
	return 0;
}

template<class DataType>
inline void LinkList<DataType>::Insert(int i, DataType x)
{
	Node<DataType> *p = first;
	int count = 0;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)throw"Location";
	else
	{
		Node<DataType> *s = new Node<DataType>;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
}

template<class DataType>
inline DataType LinkList<DataType>::Delete(int i)
{
	Node<DataType> *p = first;
	int count = 0;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL || p->next == NULL)throw"Location";
	else
	{
		Node<DataType> *q = p->next;
		int x = q->data;
		p->next = q->next;
		delete q;
		return x;
	}
}

template<class DataType>
inline void LinkList<DataType>::PrintList()
{
	Node<DataType> *p = first->next;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
}
