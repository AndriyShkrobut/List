#include "Node.h"

template<typename T>
Node<T>::Node(T data, Node * next)
{
	this->data = data;
	this->next = next;
}

template<typename T>
Node<T>::~Node()
{
}