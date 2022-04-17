#pragma once

#include <iostream>
using namespace std;
struct Node {
	int val;
	Node* next;
	Node(int _val) : val(_val), next(nullptr) {}//����������� ���������
};
class Queue {
private:
	Node* first;
	Node* last;
public:
	Queue() : first(nullptr), last(nullptr) {}//�����������
	bool is_empty() {//���� �������� �� ������� �������
		return first == nullptr;
	}

	void push(int _val) {//���������� � ����� �������
		Node* p = new Node(_val);//������� ���� �� ��������� val
		if (is_empty()) {//���� ������� ����� ,�� ����������� ��������� �� ����� � ������ �� ����� ���� � ���������� ��� ������ ������ �� ������
			first = p;
			last = p;
			return;
		}
		last->next = p;//��� ��� �� ������ ,�� �� ������ �������� ��������� ����
		last = p;
	}
	int print() {//����� �� ����� ���� �������
		if (is_empty()) return 1;
		Node* p = first;
		int size = 0;
		while (p) {//���� �� ������
			p = p->next;
			size++;
		}
		//int a = size;
		//*cout <<size<< endl;
		return size;
	}

	Node* pop() {//������� ������ ������� �������
		if (is_empty() == 1) {
			//cout << "������ ";
			return 0;
		}
		// �� ������� ������
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
		cout << "��������� � ���� ����� " << num << endl;

	}
	void get() {
		int p;
		if (q1.is_empty() == 1) {
			cout << "���� ����" << endl;
		}
		else {
			if (q1.print() == 1) {
				cout << "��������� �� ����� �����  " << q1.pop()->val << endl;
			}
			else {
				for (int i = 0; i < q1.print() + 1; i++) {
					q2.push(q1.pop()->val);
				}
				p = q1.pop()->val;
				cout << "��������� �� ����� ����� " << p << endl;
				for (int i = 0; i < q2.print(); i++) {
					q1.push(q2.pop()->val);
				}

			}
		}

	}

};

