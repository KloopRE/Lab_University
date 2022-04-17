#pragma once

#include <iostream>
using namespace std;
struct Node {
	int val;
	Node* next;
	Node(int _val) : val(_val), next(nullptr) {}//конструктор структуры
};
class Queue {
private:
	Node* first;
	Node* last;
public:
	Queue() : first(nullptr), last(nullptr) {}//конструктор
	bool is_empty() {//идет проверка на пустоту очереди
		return first == nullptr;
	}

	void push(int _val) {//добавление в конец очереди
		Node* p = new Node(_val);//создаем узел со значением val
		if (is_empty()) {//если очередь пуста ,мы присваиваем указатель на конец и начало на новый узел и выходимтак как список больше не пустой
			first = p;
			last = p;
			return;
		}
		last->next = p;//раз она не пустая ,то мы меняем значение указателя ласт
		last = p;
	}
	int print() {//вывод на экран всей очереди
		if (is_empty()) return 1;
		Node* p = first;
		int size = 0;
		while (p) {//пока не пустой
			p = p->next;
			size++;
		}
		//int a = size;
		//*cout <<size<< endl;
		return size;
	}

	Node* pop() {//удаляем первый элемент очереди
		if (is_empty() == 1) {
			//cout << "Пустой ";
			return 0;
		}
		// на пустоту списка
		Node* p = first;
		first = p->next;

		return p;
		delete p;
	}

};


class queue_list : public Queue {
private:
	Queue q1, q2;
public:
	void put(int num) {
		q1.push(num);
		cout << "Добавляем в стек число " << num << endl;

	}
	void get() {
		int p;
		if (q1.is_empty() == 1) {
			cout << "Стек пуст" << endl;
		}
		else {
			if (q1.print() == 1) {
				cout << "Извлекаем из стека число  " << q1.pop()->val << endl;
			}
			else {
				for (int i = 0; i < q1.print() + 1; i++) {
					q2.push(q1.pop()->val);
				}
				p = q1.pop()->val;
				cout << "Извлекаем из стека число " << p << endl;
				for (int i = 0; i < q2.print(); i++) {
					q1.push(q2.pop()->val);
				}

			}
		}

	}

};

