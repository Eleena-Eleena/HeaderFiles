#include "MyLib.h"
void main()
{
	system("chcp 1251>nul");

	int t, n, a, c, d = 0;
lab0:	printf("\nВведите размер массива = ");
	t = CheckIn1();
	if (t == -1)
		goto lab0;
	list* p = CrateList(t);
	Show(p);


lab1:	printf("\nВведите номер для добавления = ");
	n = CheckIn(Lenth(p));
	if (n == -1)
		goto lab1;
	p = AddElement(p, n);
	Show(p);


lab2:	printf("\nПервый номер для перемещения = ");
	a = CheckIn(Lenth(p));
	if (a == -1)
		goto lab2;
lab3:	printf("Второй номер для перемещения = ");
	c = CheckIn(Lenth(p));
	if (c == -1)
		goto lab3;
	Update(p);
	Replace(p, a, c);
	Show(p);


lab4:	printf("\nУдалить номер элемента = ");
	int l = Lenth(p) - 1;
	d = CheckIn(l);
	if (d == -1)
		goto lab4;
	Update(p);
	printf("\nДо удаления: ");
	Show(p);
	printf("\n");
	p = DeleteElement(p, d);
	printf("\nПосле удаления: ");
	Show(p);

	DeleteList(p);
	printf("\nЛист удален.");

	double res;
	res = Add(2,3);
	printf("\nСложение: %f", res);
	res = Sub(10, 3);
	printf("\nВычетание: %f", res);
	res = Mul(2, 3);
	printf("\nУмножение: %f", res);
	res = Div(2, 0);
	res = Div(6, 3);
	printf("\nДеление: %f", res);

	char pp[] = {"Hello "};
	char pp2[] = { "World" };
	char* pp3 = AddBuffers(pp, pp2);
	printf("\nОбъединенная строчка =  %s\n", pp3);

	int nn = 123489;
	char* ppp = NumberToChar(nn);
	printf("\nЧисло =  %s\n", ppp);

	char message[] = { '-','5','3','8','\0'};
	int ppp1 = CharToNumber(message);
	printf("\nЧисло =  %d\n", ppp1);
	system("pause");
}
