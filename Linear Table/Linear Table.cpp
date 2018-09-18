// Linear Table.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdlib>
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
