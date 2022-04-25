#include <iostream>
using namespace std;
struct Node {
	int x;
	Node* next;
	Node* prev;
};
struct list {
	Node* first;
	Node* last;
} rost{ NULL, NULL }; 
short ch;    // счетчик
class linkfront
{
public:
	void put_front()// добавить в начало
	{
		Node* el = new Node;
		*el = { ++ch, NULL, NULL };
		if (rost.first) {
			el->next = rost.first;
			rost.first->prev = el;
			rost.first = el;
		}
		else
			rost.last = rost.first = el;
	}

	void pop_front()// удалить в начале
	{
		if (rost.first) {
			Node* time = rost.first;
			rost.first = rost.first->next;
			rost.first->prev = NULL;
			delete time;
		}
		else
			cout << "Null!\n";
	}
};
class linkback
{
public:
	void put_back()// добавить в конец
	{
		Node* el = new Node;
		*el = { ++ch, NULL, NULL };
		if (rost.last) {
			el->prev = rost.last;
			rost.last->next = el;
			rost.last = el;
		}
		else
			rost.last = rost.first = el;
	}

	void pop_back()// удалить в конце
	{
		if (rost.last) {
			Node* time = rost.last;
			rost.last = rost.last->prev;
			rost.last->next = NULL;
			delete time;
		}
		else
			cout << "Null!\n";
	}
};

class link_both : public linkback, public linkfront
{
public:
	void show()// показать
	{
		if (rost.first) {
			Node* time = rost.first;
			while (time) {
				cout << time->x << endl;
				time = time->next;
			}
		}
		else
			cout << "Null!\n";
	}
};



int main()
{
	link_both a;
	for (;;) {
		char sym;
		cout << "put_front - w\nput_back - s\npop_front - e\npop_back - d\nShow - z\n";
		cin >> sym;
		switch (sym) {
		case 'w': a.put_front(); break;
		case 's': a.put_back(); break;
		case 'e': a.pop_front(); break;
		case 'd': a.pop_back(); break;
		case 'z': a.show(); break;
		default: continue;
		}
	}
	return 0;
}


