#include<iostream>
#include "List.h"
using namespace std;

int main()
{

	List a;
	a += 1;
	a += 1;
	a += 20;

	List b;
	b += -20;
	b += -1;

	cout << a;
	cout << b;

	List c;

	c = a & b;

	cout << c;

	return 0;
}