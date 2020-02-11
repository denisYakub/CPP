#include "List.h"
#include<iostream>
List::List()
{
	head_ = nullptr;
	tail_ = nullptr;
}

List::~List()
{
	int size = 0;
	size = this->whatSize();
	while (size)
	{
		Node* temp = head_;
		head_ = head_->next_;
		delete temp;
		size--;
	}
}



List& List::operator+=(int i)
{
	if (head_==nullptr)
	{
		head_ = new Node(i);
		
	}
	else
	{
		if (notSameObg(i))
		{
			if (MaxMin(i))
			{
				if (i < head_->data)
				{
					head_ = new Node(i, head_);

				}
				else
				{
					Node* temp = head_;
					while (temp->next_ != nullptr)
					{
						temp = temp->next_;
					}
					tail_ = temp->next_ = new Node(i);
				}
			}
			else
			{
				Node* newNode = new Node(i, nullptr);
				if (head_->data > i)
				{
					newNode->next_ = head_;
					head_ = newNode;
				}
				else
				{
					Node* p = this->head_;
					for (; p->next_; p = p->next_)
						if (p->next_->data > i)
						{
							newNode->next_ = p->next_;
							break;
						}
					p->next_ = newNode;
				}
			}
		}
	}
	return *this;
}

int& List::operator[](const int i)
{
	Node* temp = this->head_;
	int count=0;
	while (temp != nullptr)
	{
		if (count == i)
		{
			return temp->data;
		}
		temp = temp->next_;
		count++;
	}
}

bool List::MaxMin(int i)
{
	Node* temp = head_;
	int max = 0;
	int  min = 100;
	while (temp != nullptr)
	{
		if (temp->data > max)
		{
			max = temp->data;
		}
		temp = temp->next_;
	}
	Node* temp1 = head_;
	while (temp1 != nullptr)
	{
		if (temp1->data < min)
		{
			min = temp1->data;
		}
		temp1 = temp1->next_;
	}
	if ((i > max) or (i < min))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool List::notSameObg(int i)
{
	Node* temp = head_;
	while (temp != nullptr)
	{
		if (temp->data==i)
		{
			return false;
		}
		temp = temp->next_;
	}
	return true;
}

int List::whatSize()
{
	int size = 0;
	Node* temp = head_;
	while (temp != nullptr)
	{
		temp = temp->next_;
		size++;
	}
	

	return size;
}

//List operator+( List& a, const List& b)
//{
//	List::Node* temp = b.head_;
//	while (temp != nullptr)
//	{
//		a += temp->data;
//	}
//	return a;
//}

ostream& operator<<(ostream& out, const List& a)
{
	List::Node* temp = a.head_;
	out << "Your list is:";
	out << endl;
	while (temp != nullptr)
	{
		out << temp->data<<" ";
		temp = temp->next_;
	}
	out << endl;
	return out;
}

List& operator&(const List& a,const List& b)
{
	List sum;
	List::Node* temp1 = a.head_;
	List::Node* temp2 = b.head_;
	while (temp1 != nullptr)
	{
		sum += temp1->data;
		temp1 = temp1->next_;
	}
	while (temp2 != nullptr)
	{
		sum += temp2->data;
		temp2 = temp2->next_;
	}
	return sum;
}
