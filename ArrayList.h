#pragma once
#include<iostream>
#include<string>
using namespace std;

template<typename t>
class ArrayList {
private:
	int cap;
	int length;
	t* arr;
	bool is_filled()
	{
		return (length == cap);
	}
	t* expand(t* a)
	{
		cap *= 2;
		t* newarr = new t[cap];
		for (int i = 0; i < length; ++i) {
			newarr[i] = a[i];
		}
		return newarr;
	}
public:
	ArrayList()
	{
		length = 0;
		cap = 5;
		arr = new t[cap];
	}
	bool is_empty()
	{
		return (length == 0);
	}

	int get_length()
	{
		return length;
	}

	void add(t item)
	{
		if (is_filled()) {
			arr = expand(arr);
			arr[length] = item;
			++length;
		}
		else {
			arr[length] = item;
			++length;
		}
	}

	void  removeAt(int i)
	{
		t data;
		if (is_empty()) { cout << "array is empty" << endl; throw exception("array is empty");}
		else if (i >= length || i < 0) { cout << "index out of bound" << endl; throw exception("index out of bound"); }
		else if (i == length - 1) { data = arr[i]; --length; }
		else {
		
			for (int j = i; j < length - 1; ++j)
			{
				arr[j] = arr[j + 1];
			}
			--length;
		}
		
	}
	void insertItem(int i,t d)
	{
		if (is_empty()) { cout << "array is empty" << endl; throw exception("array is empty");}
		else if (i >= length || i < 0) { cout << "index out of bound" << endl; throw exception("index out of bound"); }
		else {
			if (is_filled()) { arr = expand(arr); }
			for (int j = length; j > i - 1; --j)
			{
				arr[j] = arr[j - 1];
			}
			arr[i] = d;
			++length;
		}
	}

	void editItem(int i, t d)
	{
		if (is_empty()) { cout << "array is empty" << endl; throw exception("array is empty");}
		else if (i >= length || i < 0) { cout << "index out of bound" << endl; throw exception("index out of bound");}
		else {
			arr[i] = d;

		}
	}
	t get(int i)
	{
			t data;
			if (is_empty()) { cout << "array is empty" << endl; throw exception("array is empty");}
			else if (i >= length || i < 0) { cout << "index out of bound" << endl; throw exception("index out of bound"); }
			else { data = arr[i]; }
			return data;	
	}
	int indexOf(t item)
	{
		{
			if (is_empty()) { cout << "array is empty" << endl;  throw exception("array is empty");}
			else {
				bool found = false;
				int j = 0;
				for (j; j < length; ++j)
				{
					if (arr[j] == item) {
						found = true;
						break;
					}
				}
				if(found)
				return j;
			}
			return -1;
		}

	}
	bool contains(t item)
	{
		{
			return (indexOf(item) != -1);
		}
	}
	void display()
	{
		{

			if (is_empty()) { cout << "array is empty" << endl;  throw exception("array is empty");}
			else {

				cout << "[";
				for (int j = 0; j < length - 1; ++j)
				{
					cout << arr[j] << ", ";
				}
				cout << arr[length - 1] << "]" << endl;
			}
		}
	}
};
