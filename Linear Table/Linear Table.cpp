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
int LocateElem(SQlist L, Elemtype e);
void ListInsert(SQlist L, int i, Elemtype e);

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
	if (i<1 || i>L.length)throw "INPUT OUT OF SIZE OF LIST";
	return L.elem[i - 1];
}

int LocateElem(SQlist L, Elemtype e)
{
	int i = 0;
	for ( i = 0; i < L.length; i++)
	{
		if (L.elem[i]==e)
		{
			return i + 1;
			break;
		}
	}
	if (i==L.length)
	{
		return 0;
	}
}

void ListInsert(SQlist L, int location, Elemtype e)
{
	if (location<1 || location>L.length)exit(OVERFLOW);
	for (int i = L.length; i >= location; i--)
	{
		L.elem[i] = L.elem[i - 1];
	}
	L.elem[location - 1] = e;
	L.length++;
	if (L.length>=L.listsize)
	{
		
		Elemtype *BiggerList = (Elemtype *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(Elemtype));
		if (!BiggerList) {
			throw "NO ENGOUGH MENMERY!";
		}
		else
		{
			L.elem = BiggerList;
			L.listsize += LISTINCREMENT;
		}
		
	}
}
