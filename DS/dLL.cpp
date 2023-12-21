#include <bits/stdc++.h>
using namespace std;
class node
{
public:
	int data;
	node *right;
	node *left;
	node()
	{
		data = 0;
		right = nullptr;
		left = nullptr;
	}
	node(int data)
	{
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};
class dll
{
public:
	node *head;
	dll() { head = nullptr; }

	void insert_head(int);
	void insert_tail(int);
	void insert_at(int, int);
	void del_at(int);
	void printlist();
	void del_head();
	void del_tail();
};

void dll::del_head()
{
	if (head == nullptr)
	{
		cout << "List is empty." << endl;
		return;
	}

	// Only one node in the list
	if (head->right == nullptr)
	{
		node *temp = head;
		delete temp;
		head = nullptr;
		return;
	}
	node *temp = head;
	head = head->right;
	head->left = nullptr;
	delete temp;
	return;
}
void dll ::del_tail()
{
	if (head == nullptr)
	{
		cout << "List is empty." << endl;
		return;
	}
	// Only one node in the list
	if (head->right == nullptr)
	{
		node *temp = head;
		delete temp;
		head = nullptr;
		return;
	}

	// deletion of last node
	node *temp = head;
	while (temp->right->right != nullptr)
	{
		temp = temp->right;
	}
	node *temp1 = temp->right;
	delete (temp1);
	temp->right = nullptr;
}

void dll::del_at(int pos)
{
	if (head == nullptr)
	{
		cout << "List is empty." << endl;
		return;
	}
	// Only one node in the list
	if (head->right == nullptr)
	{
		node *temp = head;
		delete temp;
		head = nullptr;
		return;
	}

	int len = 0;
	node *temp = head;
	while (temp != nullptr)
	{
		temp = temp->right;
		len++;
	}

	if (len < pos)
	{
		cout << "index out of 007" << endl;
		return;
	}

	if (pos == 1)
	{
		del_head();
		return;
	}
	if (pos == len)
	{
		del_tail();
		return;
	}

	while (pos-- > 1)
	{
		temp = temp->right;
	}
	temp->left->right = temp->right;
	if (pos != len)
		temp->right->left = temp->left;
	delete temp;
}

void dll::insert_head(int data)
{
	node *p = new node(data);
	if (head == nullptr)
	{
		head = p;
		return;
	}
	head->left = p;
	p->right = head;
	head = p;
}
void dll::insert_tail(int data)
{
	node *p = new node(data);
	if (head == nullptr)
	{
		head = p;
		return;
	}
	node *temp = head;
	while (temp->right != nullptr)
	{
		temp = temp->right;
	}
	temp->right = p;
	p->left = temp;
}
void dll::insert_at(int pos, int data)
{
	if (!head)
	{
		node *p = new node(data);
		head = p;
		return;
	}
	if (pos == 1)
	{
		insert_head(data);
		return;
	}
	int len = 0;
	node *temp = head;
	while (temp != nullptr)
	{
		temp = temp->right;
		len++;
	}
	if (pos == len)
	{
		insert_tail(data);
		return;
	}
	node *p = new node(data);
	temp = head;
	while (pos-- > 2)
	{
		temp = temp->right;
	}
	p->right = temp->right;
	p->right->left = p;
	p->left = temp;
	temp->right = p;
}
void dll::printlist()
{
	node *temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << "<=>";
		temp = temp->right;
	}
	cout << "NULL" << endl;
}
int main()
{
	dll d;

	// Test Case 1: Insert at head
	d.insert_head(10);
	d.printlist(); // Output: 10<=>NULL

	// Test Case 2: Insert at tail
	d.insert_tail(20);
	d.insert_tail(30);
	d.printlist(); // Output: 10<=>20<=>30<=>NULL

	// Test Case 3: Insert at a specific position
	d.insert_at(2, 25);
	d.printlist(); // Output: 10<=>25<=>20<=>30<=>NULL

	// Test Case 4: Delete from head
	d.del_head();
	d.printlist(); // Output: 25<=>20<=>30<=>NULL

	// Test Case 5: Delete from tail
	d.del_tail();
	d.printlist(); // Output: 25<=>20<=>NULL

	// Test Case 6: Delete from a specific position
	d.del_at(2);
	d.printlist(); // Output: 25<=>NULL

	// Test Case 7: Delete from an empty list
	d.del_at(1); // Output: List is empty.

	return 0;
}
