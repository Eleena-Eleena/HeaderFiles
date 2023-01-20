#pragma once
typedef struct s_list
{
	int field;
	struct s_list* next;
} list;

list* Element(list* p, int n);
int lenth(list* p, int count);
int Lenth(list* p);
list* list1(int i, int t);
list* CrateList(int t);
list* AddElement(list* p, int n);
void Show(list* p);
void Replace(list* p, int a, int c);
void update(list* p, int count);
void Update(list* p);
list* DeleteElement(list* p, int d);
int CheckIn(int l);
int CheckIn1();
void DeleteList(list* p);

double Add(double a, double b);
double Sub(double a, double b); 
double Mul(double a, double b);
double Div(double a, double b);

char* AddBuffers(char* p1, char* p2);
char* NumberToChar(int n);
int CharToNumber(char* p);