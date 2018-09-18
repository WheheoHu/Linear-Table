// Linear Table.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdlib>
#include <iostream>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef char Elemtype;
typedef struct {
	Elemtype *elem;
	int length;
	int listsize;
}SQlist;

void CreateList(SQlist &L, Elemtype elem[], int n);
void DestoryList(SQlist &L);
bool ListEmpty(SQlist L);
int ListLength(SQlist L);
void DispList(SQlist L);
Elemtype GetElem(SQlist L, int i);


int main()
{
	
    return 0;
}

void CreateList(SQlist & L, Elemtype elemayy[], int n)
{ 
	L.elem = (Elemtype*)malloc(LISTINCREMENT * sizeof(Elemtype));
	if (!L.elem)exit(OVERFLOW);
	for (int i = 0; i < n; i++)
	{
		L.elem[i] = elemayy[i];
	}
	L.length = n;
	L.listsize = LIST_INIT_SIZE;
}

void DestoryList(SQlist & L)
{
	free(L.elem);
}

bool ListEmpty(SQlist L)
{
	return (L.length==0);
}

int ListLength(SQlist L)
{
	return (L.length);
}

void DispList(SQlist L)
{
	if (L.length == 0)return;
	for (int i = 0; i < L.length; i++)
	{
		std::cout << L.elem[i] << " ";
	}
	std::cout << std::endl;
}

Elemtype GetElem(SQlist L, int i)
{
	if (i<1 || i>L.length)return 0;
	return L.elem[i - 1];
}
