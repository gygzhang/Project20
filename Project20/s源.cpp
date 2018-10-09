#include<stdio.h>
#include<stdlib.h>
struct Node;
typedef struct Node *PNode;
struct Node {
	float coef;
	int exp;
	PNode next;
};

PNode createpoly()
{
	PNode h = NULL, p = NULL, q;
	int e;
	float c;
	printf("������ϵ����ָ��(ָ���Ӵ�С)��\n");
	scanf("%f,%d", &c, &e);
	while (e != 0 || c != 0)
	{
		p = (PNode)malloc(sizeof(struct Node));
		p->coef = c;
		p->exp = e;
		p->next = NULL;
		if (h == NULL)
			h = p;
		else
			q->next = p;
		q = p;
		printf("������ϵ����ָ����\n");
		scanf("%f,%d", &c, &e);
	}
	return h;
}

void  outputpoly(PNode h)
{
	PNode p;
	p = h;
	while (p != NULL)
	{
		if (p->exp == 0)
			printf("%.2f", p->coef);
		else
		{
			printf("%.2fx^%d", p->coef, p->exp);
		}
		p = p->next;
		if (p != NULL)
			printf("+");
	}
	printf("\n");
}

PNode addpoly(PNode h1, PNode h2)
{
	PNode p, r = NULL, s1, s2, s = NULL;
	float c;
	int e;
	s1 = h1;
	s2 = h2;
	while (s1 != NULL && s2 != NULL)
	{
		if (s1->exp == s2->exp)
		{
			c = s1->coef + s2->coef;
			e = s1->exp;
			s1 = s1->next;
			s2 = s2->next;
		}
		else if (s1->exp > s2->exp)
		{
			c = s1->coef;
			e = s1->exp;
			s1 = s1->next;
		}
		else
		{
			c = s2->coef;
			e = s2->exp;
			s2 = s2->next;
		}
		if (c != 0)
		{
			p = (PNode)malloc(sizeof(struct Node));
			p->coef = c;
			p->exp = e;
			p->next = NULL;
			if (s == NULL)
				s = p;
			else
				r->next = p;
			r = p;
		}
	}
	while (s1 != NULL)
	{
		c = s1->coef;
		e = s1->exp;
		s1 = s1->next;
		if (c != 0)
		{
			p = (PNode)malloc(sizeof(struct Node));
			p->coef = c;
			p->exp = e;
			p->next = NULL;
			if (s == NULL)
				s = p;
			else
				r->next = p;
			r = p;
		}
	}
	while (s2 != NULL)
	{
		c = s2->coef;
		e = s2->exp;
		s2 = s2->next;
		if (c != 0)
		{
			p = (PNode)malloc(sizeof(struct Node));
			p->coef = c;
			p->exp = e;
			p->next = NULL;
			if (s == NULL)
				s = p;
			else
				r->next = p;
			r = p;
		}
	}
	return s;
}

void deletepoly(PNode h)
{
	PNode p, r = h;
	while (r != NULL)
	{
		p = r->next;
		free(r);
		r = p;
	}
}

void main()
{
	PNode head1, head2, head;
	printf("������һ������ʽ��\n");
	head1 = createpoly();
	printf("�����ڶ�������ʽ��\n");
	head2 = createpoly();
	printf("����������ʽ��ӣ�\n");
	head = addpoly(head1, head2);
	outputpoly(head);
	deletepoly(head);
	_sleep(2000);
}
