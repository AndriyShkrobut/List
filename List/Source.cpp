#include "List.h"
#include "List.cpp"
using namespace std;

int main()
{
	List<int>l;
	ifstream file("data.txt");
	l.readFile(file);
	l.print(cout);
	l.pushBack(4096);
	l.print(cout);
	l.popFront();
	l.print(cout);
	l.pushFront(1);
	l.print(cout);
	l.popBack();
	l.print(cout);
	l.insertEl(0, 7);
	l.print(cout);
	l.deleteEl(7);
	l.print(cout);
	l.clear();
	l.insertEl(1, 0);
	l.deleteEl(1);
	l.print(cout);
	system("pause");
	return 0;
}