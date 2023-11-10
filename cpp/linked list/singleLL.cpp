#include <iostream>
using namespace std;
class node
{
public:
    node *next;
    int data;

    node()
    {
        next = nullptr;
        data = 0;
    }
    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class linkedlist
{
    node *head;

public:
    linkedlist() { head = nullptr; }

    void insertnode(int);

    void deletenode(int);

    void printlist();
};
void linkedlist::insertnode(int data)
{
    node *p = new node(data);

    if (head == nullptr)
    {
        head = p;
        return;
    }
    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = p;
}
void linkedlist::deletenode(int pos)
{
    node *temp1 = nullptr;
    node *temp = head;
    int len;
    if (pos == 1)
    {
        head = temp->next;
        delete temp;
    }
    while (temp != nullptr)
    {
        temp = temp->next;
        len++;
    }
    if (pos > len)
    {
        cout << "index out of range" << endl;
    }
    temp = head;
    while (pos-- > 2)
    {
        temp = temp->next;
    }
    temp1 = temp;
    temp = temp->next;
    temp1->next = temp->next;
    delete temp;
}
void linkedlist::printlist()
{
    if (head == nullptr)
    {
        cout << "empty list" << endl;
        return;
    }
    node *temp = head;
    cout << "head->";
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;
}
int main()
{
    linkedlist l;
    l.insertnode(1);
    l.insertnode(2);
    l.insertnode(3);
    l.insertnode(4);
    l.printlist();
    cout << endl;
    l.deletenode(3);
    l.printlist();
    return 0;
}
