#include "STACK.h"
#include <string>
class publication
{
private:
	string title;
	float price;
	
public:
	
	void getdata()
	{
		
		cout << '\n' << "Введите название книги: ";
		cin >> title;
		cout << '\n' << "Введите цену книги: ";
		cin >> price;
	}
	void putdata()
	{
		cout << '\n' << "Название книги:" << title;
		cout << '\n' << "Цена книги: " << price;
	}
};

class Book : publication
{
private:
	int pages;
public:
	void getdata()
	{
		publication::getdata();
		cout << '\n' << "Введите колличество страниц: ";
		cin >> pages;
	}
	void putdata()
	{
		publication::putdata();
		cout << '\n' << "Колличество страниц: " << pages;
	}
};

class tape : publication
{
private:
	float time;
public:
	void getdata()
	{
		publication::getdata();
		cout << '\n' << "Введите время звучания: ";
		cin >> time;
	}
	void putdata()
	{
		publication::putdata();
		cout << '\n' << "Время звучания: " << time;
	}
};
void main()
{system("chcp 1251>nul");
	system("cls");
	queue_list s;
	s.put(5);
	s.get();
	s.get();
	s.put(53);
	s.put(30);
	s.put(89);
	s.get();
	s.put(20);
	s.put(200);
	s.put(85);
	s.get();
	s.put(80);
	tape a1;
	Book a2;

	a1.getdata();
	a2.getdata();

	a1.putdata();
	a2.putdata();

}

