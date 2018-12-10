#include "List.h"

template<typename T>
List<T>::List()
{
	head = nullptr;
	size = 0;
}

template<typename T>
int List<T>::length()
{
	return size;
}

template<typename T>
void List<T>::pushFront(T data)
{
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void List<T>::pushBack(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>*temp = this->head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = new Node<T>(data);
	}
	size++;
}

template<typename T>
void List<T>::popFront()
{
	if (head != nullptr)
	{
		Node<T> *temp = head;
		head = head->next;
		delete temp;
		size--;
	}
}

template<typename T>
void List<T>::popBack()
{
	deleteEl(size - 1);
}

template<typename T>
void List<T>::insertEl(T data, int index)
{
	if (index <= size)
	{
		if (index == 0)
		{
			pushFront(data);
		}
		else
		{
			Node<T>*previous = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->next;
			}
			previous->next = new Node<T>(data, previous->next);
			size++;
		}
	}
}

template<typename T>
void List<T>::deleteEl(int index)
{
	if ((head != nullptr) && (index < size))
	{
		if (index == 0)
		{
			popFront();
		}
		else
		{
			Node<T>*previous = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->next;
			}
			Node<T>*toDelete = previous->next;
			previous->next = toDelete->next;
			delete toDelete;
			size--;
		}
	}
}

template<typename T>
void List<T>::read()
{
	int _size;
	T data;
	cout << "Enter size of List - ", cin >> _size;
	while (_size)
	{
		cin >> data;
		pushBack(data);
		_size--;
	}	
}

template<typename T>
void List<T>::readFile(ifstream & file)
{
	if (file)
	{
		T data;
		while (!file.eof())
		{
			file >> data;
			pushBack(data);
		}
		file.close();
	}
	else
	{
		cout << "File isn't opened.";
		return;
	}
}

template<typename T>
void List<T>::print(ostream & os)
{
	Node<T>*temp = head;
	while (temp != nullptr)
	{
		os << temp->data << "    ";
		temp = temp->next;
	}
	os << "\n\n";
}

template<typename T>
T & List<T>::operator[](const int index)
{
	int current = 0;
	Node<T>*temp = this->head;
	while (temp != nullptr)
	{
		if (current == index)
		{
			return temp->data;
		}
		temp = temp->next;
		current++;
	}
}

template<typename T>
void List<T>::clear()
{
	while (head != nullptr)
	{
		Node<T>*temp = head;
		head = head->next;
		delete temp;
		size--;
	}
}

template<typename T>
List<T>::~List()
{
	clear();
}