#pragma once
#include "Node.h"
#include "Node.cpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef _LIST_H_
#define _LIST_H_

template<typename T>
class List
{
	Node<T> *head;
	int size;
public:
	List();
	int length();
	void pushFront(T data);
	void pushBack(T data);
	void popFront();
	void popBack();
	void insertEl(T data, int index);
	void deleteEl(int index);
	void read();
	void readFile(ifstream & file);
	void print(ostream & os);
	void clear();
	T& operator[](const int index);
	~List();
};
#endif // !_LIST_H_
