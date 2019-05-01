#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Sequential_list.h"
using namespace std;

int main()
{
	int A[7] = {1,2,3,5,4,6,3};
	int B[8] = { 2,3,5,5,3,2,2,5 };
	SeqList<int> a(A,7);
	SeqList<int> b(B, 8);

	//Subscript zero is the low order
	SeqList<int> c = Add(a, b);

	c.PrintList();

	system("pause");
	return 0;
}
