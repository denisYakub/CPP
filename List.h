#pragma once
#include <iomanip>
#include<iostream>
using namespace std;
class List
{
public:
	List();
	virtual ~List();
	List& operator +=(int i);
	int& operator [](const int i);
	bool MaxMin(int i);
	bool notSameObg(int i);
	int whatSize();
	friend ostream& operator<<(ostream &out,const List&a);
	friend List& operator &(const List&a, const List&b);
private:
	class Node
	{
	public:
		int data;
		Node* next_;
		Node(int data=0,Node*next_=nullptr)
		{
			this->data = data;
			this->next_ = next_;
		}
	};
	Node* head_;
	Node* tail_;
};

