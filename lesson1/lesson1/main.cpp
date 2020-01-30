#include <iostream>
#include <cassert>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(int data = 0)
	{
		this->data = data;
		this->next = nullptr;
	}
};

class MyList
{
public:
	Node* head;
	int length;
	MyList(int data)
	{
		head = new Node(data);
		this->length = 1;
	}
	void add(int data)
	{
		Node* temp = this->head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = new Node(data);
		++this->length;
	}
	int get(int index)
	{
		assert(index >= 1 && index <= length);
		Node* temp = this->head;
		for (int i = 0; i < index - 1; ++i)
		{
			temp = temp->next;
		}
		return temp->data;
	}
};

int main()
{	
	MyList l(1);
	cout << l.get(10);

	return 0;
}