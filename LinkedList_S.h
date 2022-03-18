#pragma once
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

template<class t>
class LinkedList_S{
private:
    class node {
    public:
        t data;
        node* next;
        node(t d) {
            data = d;
        }
        node(t d,node*ptr) {
            data = d;
            next = ptr;
        }
    };
    node* head;
    node* tail;
    int size;

public:
    LinkedList_S():size(0),head(nullptr),tail(nullptr) { }

    bool is_empty() {
        return (size == 0);
    }
    void add(t d) {
        if (is_empty()) {
            head = tail = new node(d);
            ++size;
        }
        else {
            node* temp = new node(d);
            tail->next = temp;
            tail = temp;
            ++size;
        }
    }
    void remove(int i) {
        if (is_empty()) { cout << "linked list is empty" << endl;  throw exception("linked list is empty"); }
        else if (i<0 || i>size) { cout << "index out of bound" << endl;  throw exception("index out of bound");
        }
        else {
            node* trav = head;
            node* pre=trav;
            while (trav != nullptr && i > 0)
            {
                pre = trav;
                trav = trav->next;
                --i;
            }
            pre->next = trav->next;
            trav->next = NULL;
            delete trav;
            --size;
        }
    }
    void edit(int i, t d) {
        if (is_empty()) { cout << "linked list is empty" << endl; throw exception("linked list is empty");}
        else if(i<0 || i>=size) { cout << "index out of bound" << endl;  throw exception("index out of bound"); }
        else {
            node* trav = head;
            while (trav != nullptr && i > 0)
            {
                trav = trav->next;
                --i;
            }
            trav->data = d;
        }
    }
    void setAt(int i, t d) {
        if (i<0 || i>size) { cout << "index out of bound" << endl; throw exception("index out of bound");
        }
        else if (is_empty() || i == size) { add(d); }
        else {
            node* temp = new node(d);
            node* trav = head;
            while (trav != nullptr && i > 1)
            {
                trav = trav->next;
                --i;
            }
            temp->data = d;
            temp->next = trav->next;
            trav->next = temp;
            ++size;
        }
    }

    t get(int i) {
        if (i < 0 || i >= size) { cout << "index out of bound" << endl; throw exception("index out of bound"); }
        else if (is_empty())  { cout << "linked list is empty" << endl; throw exception("linked list is empty"); }
        else {
            node* trav = head;
            while (trav != nullptr && i > 0)
            {
                trav = trav->next;
                --i;
            }
            return trav->data;
        }
    }
    int indexOf(t d) {
        if (is_empty()) { cout << "linked list is empty" << endl;  throw exception("linked list is empty");
        }
        else {
            for (int i = 0; i < size; i++)
            {
                if (get(i) == d) {
                    return i;
                }
            }
        }
        return -1;
    }
    bool contains(t d) {
        return(indexOf(d) != -1);
    }

    int getSize() {
        return size;
    }
    void display() {
        if (is_empty()) { cout << "linked list is empty" << endl;  throw exception("linked list is empty");
        }
        else {
            cout << "[";
            for (int i = 0; i < size-1; i++)
            {
                cout << get(i) << "; ";
            }
            cout << get(size - 1) << "]" << endl;
        }
    }
    
};