#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
typedef struct pos
{
	int x;
	int y;
}PosType;
typedef struct element
{
	PosType seat;
	int dir;
	struct element *next;
}ElemType;
ElemType *Init()
{
	ElemType *head, *p;
	head = (ElemType*)malloc(sizeof(ElemType));
	p = (ElemType*)malloc(sizeof(ElemType));
	head->next = p;
	p->seat.x = 1;
	p->seat.y = 0;
	p->dir = 2;
	p->next = NULL;
	return head;
}
void Pop(int i, int j, ElemType *p)
{
	ElemType *m;
	m = (ElemType*)malloc(sizeof(ElemType));
	m->seat.x = i;
	m->seat.y = j;
	m->next = p->next;
	p->next = m;
	if (m->next != NULL)
	{
		if (m->seat.x - m->next->seat.x == 1)
			m->dir = 1;
		else if (m->seat.x - m->next->seat.x == -1)
			m->dir = 3;
		else if (m->seat.y - m->next->seat.y == 1)
			m->dir = 2;
		else
			m->dir = 4;
	}
	else
		m->dir = 1;
}
void Push(ElemType *p)
{
	if (p->next == NULL)
		return;
	ElemType *q;
	q = p->next;
	p->next = q->next;
		free(q);
}
int Move(ElemType *p, int(*a)[10], int i, int j)
{
	Pop(i, j, p);;
	if (i == 9 && j == 8)
		return 1;
	else
	{

		{
			switch (p->next->dir)
			{
			case 1: {
				if (a[i][j + 1] == 0)
				{
					Move(p, a, i, j + 1);
				}
				else if (a[i][j - 1] == 0)
				{
					Move(p, a, i, j - 1);
				}
				else if (a[i + 1][j] == 0)
				{
					Move(p, a, i + 1, j);
				}
				else
				{
					a[i][j] = 1;
					Push(p);
					Move(p, a, p->next->seat.x, p->next->seat.y);
					
				}}break;
			case 2: {
				if (a[i + 1][j] == 0)
				{
					Move(p, a, i + 1, j);
				}
				else if (a[i][j + 1] == 0)
				{
					Move(p, a, i, j + 1);
				}
				else if (a[i - 1][j] == 0)
				{
					Move(p, a, i - 1, j);
				}
				else
				{
					a[i][j] = 1;
					Push(p);
					Move(p, a, p->next->seat.x, p->next->seat.y);
					
				}}break;
			case 3: {
				if (a[i - 1][j] == 0)
				{
					Move(p, a, i - 1, j);
				}
				else if (a[i][j + 1] == 0)
				{
					Move(p, a, i, j + 1);
				}
				else if (a[i][j - 1] == 0)
				{
					Move(p, a, i, j - 1);
				}
				else
				{
					a[i][j] = 1;
					Push(p);
					Move(p, a, p->next->seat.x, p->next->seat.y);
					
				}
			}break;
			case 4: {
				if (a[i + 1][j] == 0)
				{
					Move(p, a, i + 1, j);
				}
				else if (a[i][j-1] == 0)
				{

					Move(p, a, i, j + 1);
				}
				else if (a[i - 1][j] == 0)
				{

					Move(p, a, i - 1, j);
				}
				else
				{
					a[i][j] = 1;
					Push(p);
					Move(p, a, p->next->seat.x, p->next->seat.y);
					
				}
			};
			}
		}
	}
}
int main(void)
{
	int  a[11][10] = { { 1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,1,1,1,1,1,0,1 },
	{ 1,0,0,1,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,1,1 },
	{ 1,0,1,1,1,0,0,1,0,1 },
	{ 1,0,0,0,1,0,0,0,0,1 },
	{ 1,0,1,0,0,0,1,0,1,1 },
	{ 1,0,1,1,1,1,0,0,1,1 },
	{ 1,1,1,0,0,0,1,0,1,1 },
	{ 1,1,1,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1 } };
	ElemType *p, *q;
	int i = 1, j = 1;
	p = Init();
	Move(p, a, i, j);
	q = p->next;
	while (q->next)
	{
		if (q->seat.x ==q->next->seat.x&&q->seat.y==q->next->seat.y)
			Push(q);
		q = q->next;
	}
	q = p->next;
	while (q != NULL)
	{
		printf("%d%d ", q->seat.x, q->seat.y);
		q = q->next;
	}
	system("pause");
}


