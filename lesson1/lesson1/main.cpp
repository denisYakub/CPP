#include <iostream>

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
		if (index > this->length || index < 1)
		{
			// бросить исключение
			return -1;
		}
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
	for (int i = 2; i < 11; ++i)
	{
		l.add(i * i);
	}
	for (int i = 1; i < 11; ++i)
	{
		cout << l.get(i) << " ";
	}
	return 0;
}