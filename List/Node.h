#pragma once
#ifndef _NODE_H_
#define _NODE_H_

template<typename T>
class Node
{
public:
	Node *next;
	T data;
	Node(T data = T(), Node *next = nullptr);
	~Node();
};
#endif // !_NODE_H_