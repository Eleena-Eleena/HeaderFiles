#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct s_list {
	int field;
	struct s_list* next;
} list;

list* Element(list* p, int n) {

	if (p->field == n) {
		return p;
	}
	return Element(p->next, n);
}

int lenth(list* p, int count) {
	count++;
	if (p->next == (list*)-1)
		return count;
	return lenth(p->next, count);
}

int Lenth(list* p) {
	int count = 0;
	if (p->field != 0)
		return 0;
	return lenth(p, count);
}

list* list1(int i, int t) {
	list* p = (list*)malloc(sizeof(list));
	p->field = (int)i;
	if (i == t) {
		p->next = (list*)-1;
		return p;
	}
	p->next = list1(++i, t);
	return p;
}

list* CrateList(int t) {
	int i = 0;
	return  list1(0, t - 1);
}

list* AddElement(list* p, int n) {
	if (n == 0) {
		list* p1 = Element(p, n);
		list* p3 = (list*)malloc(sizeof(list));
		p3->field = n;
		p3->next = p1;
		p = p3;
		return p;
	}
	else if (n == Lenth(p)) {
		list* p1 = Element(p, n - 1);
		list* p3 = (list*)malloc(sizeof(list));
		p3->field = n;
		p3->next = (list*)-1;
		p1->next = p3;
		return p;
	}
	else {
		list* p1 = Element(p, n - 1);
		list* p2 = p1->next;
		list* p3 = (list*)malloc(sizeof(list));
		p3->field = (int)n;
		p1->next = p3;
		p3->next = p2;
		return p;
	}
}

void Show(list* p) {
	printf("%d ", p->field);
	if (p->next == (list*)-1) {
		return;
	}
	Show(p->next);
}

void Replace(list* p, int a, int c) {
	list* p1 = Element(p, a);
	list* p2 = Element(p, c);
	int field = p1->field;
	p1->field = p2->field;
	p2->field = field;
}

void update(list* p, int count) {
	p->field = count;
	if (p->next == (list*)-1) {
		return;
	}
	update(p->next, ++count);
}

void Update(list* p) {
	int count = 0;
	p->field = count;
	if (p->next == (list*)-1) {
		return;
	}
	update(p->next, ++count);
}
list* DeleteElement(list* p, int d) {
	if (d == 0) {
		list* p1 = Element(p, d);
		list* p2 = p1->next;
		p = p2;
		free(p1);
		return p;
	}
	else if (d == Lenth(p) - 1) {
		list* p1 = Element(p, d - 1);
		list* p2 = p1->next;
		p1->next = (list*)-1;
		free(p2);
		return p;
	}
	else {
		list* p1 = Element(p, d - 1);
		list* p2 = p1->next;
		list* p3 = p2->next;
		p1->next = p3;
		free(p2);
		return p;
	}
}
int CheckIn(int l) {
	int m = 0;
	int i = scanf("%d", &m);
	if (i == 0 || m == EOF || m < 0 || m > l) {
		printf("\nНеверно набрано число \n");
		while ((m = getchar()) != EOF && m != '\n');
		return -1;
	}
	return m;
}

int CheckIn1() {
	int m = 0;
	int i = scanf("%d", &m);
	if (i == 0 || m == EOF || m < 0) {
		printf("\nНеверно набрано число \n");
		while ((m = getchar()) != EOF && m != '\n');
		return -1;
	}
	return m;
}

void DeleteList(list* p) {
	Update(p);
	int l = Lenth(p) - 1;
	for (int i = l; i > 0; i--)
	{
		list* p1 = Element(p, i);
		free(p1);
	}
}

double Add(double a, double b)
{
	return a + b;
}
double Sub(double a, double b)
{
	return a - b;
}
double Mul(double a, double b)
{
	return a * b;
}
double Div(double a, double b)
{
	if (b == 0)
	{
		printf("\nНа 0 делить нельзя");
		return 0;
	}
	return a / b;
}

char* AddBuffers(char* p1, char* p2)
{
	int res1 = strlen(p1);
	int res2 = strlen(p2);
	char* p3 = (char*)malloc((res1 + res2 +1) * sizeof(char));
	int i = 0;
	for (i = 0; i < res1; i++)
		p3[i] = p1[i];
	for (int j = 0; j < res2; j++) {
		p3[i] = (char)p2[j];
		i++;
	}
	p3[i] = (int)'\0';
	return p3;
}

char* NumberToChar(int n)
{
	char* c;
	c = (char*)malloc(10 * sizeof(char));
	int v = 0; 
	
	while (n > 9)
	{
		c[v++] = (n % 10) + '0';
		n = n / 10;
	}
	c[v++] = (char)n + '0';
	c[v] = '\0';
	char t;
	
	for (int i = 0; i < v / 2; i++)
	{
		t = c[i];
		c[i] = c[v - 1 - i];
		c[v - 1 - i] = t;
	}
	v = 0;
	while (c[v] != '\0')
		printf("%c", c[v++]);
	printf("\n");
	return c;
}

int CharToNumber(char* p) 
{
	int n = strlen(p);
	int number = 0;
	int mult = 1;

	while (n--)
	{
		if ((p[n] < '0' || p[n] > '9') && p[n] != '-') {
			if (number)
				break;
			else
				continue;
		}

		if (p[n] == '-') {
			if (number) {
				number = -number;
				break;
			}
		}
		else {            
			number += (p[n] - '0') * mult;
			mult *= 10;
		}
	}

	return number;
}