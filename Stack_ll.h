#pragma once
#include<iostream>
#include<string>
using namespace std;

template<typename t>
class Stack_ll {
private:
	class node {
	public:
		t data;
		node* next;
	};
	node* head;
	node* tail;
	int size;
public:
	Stack_ll() {
		size = 0;
		head = nullptr;
		tail = nullptr;
	}
	bool is_empty() {
		return (size == 0);
	}

	void push(t d) {
		if (is_empty()) {
			head = tail = new node();
			head->data = d;
			++size;
		}
		else {
			node* temp = new node();
			temp->data = d;
			temp->next = head;
			head = temp;
			++size;
		}
	}

	void pop() {
		if (is_empty()) {
			cout << "stack is empty " << endl;
		}
		else {
			node* temp = head->next;
			head->next = NULL;
			delete head;
			head = temp;
			--size;
		}
	}

	int getSize() {
		return size;
	}

	t peekf() {
		if (is_empty()) {
			cout << "stack is empty " << endl;
			throw exception();
		}
		return head->data;
	}

	t peekl() {
		if (is_empty()) {
			cout << "stack is empty " << endl;
			throw exception();
		}
		return tail->data;
	}

	t get(int i) {
		node* trav = head;
		if (is_empty()) {
			cout << "stack is empty " << endl;
			throw exception();
		}
		else if (i>size||i<0) {
			cout << "index out of bound" << endl;
			throw exception();
		}
		else {
			
			while (trav != NULL && i > 0)
			{
				trav = trav->next;
				--i;
			}
			
		}
		return trav->data;
	}

	bool contain(t d) {
		if (is_empty()) {
			cout << "stack is empty " << endl;
			return false;
		}
		else {
			bool found = false;
			node* trav = head;
			while (trav != nullptr )
			{
				if (trav->data == d) {
					found = true;
					break;
			    }
				trav = trav->next;
			}
			if (found)
				return true;

		}
		return false;
	}

	void display() {
		if (is_empty()) {
			cout << "stack is empty " << endl;
			throw exception();
		}
		else {
			cout << "[";
			node* trav = head;
			while (trav != tail)
			{
				cout << trav->data << ", ";
				trav = trav->next;
			}
			cout << trav->data << "]" << endl;

		}
	}

};
