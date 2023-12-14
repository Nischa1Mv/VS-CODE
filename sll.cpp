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
        next = nullptr;
    }
};
class slinkedlist
{
    node *head;

public:
    slinkedlist() { head = nullptr; }
    void insert(int);
    void insertbegin(int);
    void insertend(int);
    void insertpos(int, int);
    void deleteend();
    void deletebegin();
    void deletepos(int);
    void printlist();
};

void slinkedlist::insert(int data)
{
    node *p = new node(data);
    if (head == nullptr)
    {
        head = p;
        return;
    }
    insertend(data);
}
void slinkedlist ::insertbegin(int data)
{
    node *p = new node(data);
    if (head == nullptr)
    {
        head = p;
        return;
    }
    p->next = head;
    head = p;
}
void slinkedlist ::insertend(int data)
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
void slinkedlist ::insertpos(int pos, int data)
{
    node *p = new node(data);
    if (head == nullptr)
    {
        head = p;
        return;
    }
    if (pos == 1)
    {
        insertbegin(data);
    }
    node *temp = head;
    while (pos-- > 2)
    {
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cout << " position invalid" << endl;
        delete p;
        return;
    }
    p->next = temp->next;
    temp->next = p;
}
void slinkedlist ::deletebegin()
{
    if (head == nullptr)
    {
        cout << "list is empty" << endl;
        return;
    }
    node *temp = head;
    head = temp->next;
    delete temp;
}
void slinkedlist ::deleteend()
{
    if (head == nullptr)
    {
        cout << "the list is empty" << endl;
        return;
    }
    node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next->next;
    temp->next = nullptr;
}
void slinkedlist ::deletepos(int pos)
{
    if (pos == 1)
    {
        deletebegin();
    }
    node *temp = head;
    while (pos-- > 2)
    {
        temp = temp->next;
    }
    if (temp->next == nullptr)
    {
        cout << "invalid position" << endl;
        return;
    }
    node *temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
}
void slinkedlist ::printlist()
{
    if (head == nullptr)
    {
        cout << "list is empty" << endl;
        return;
    }
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;
}
int main()
{
    slinkedlist s;
    s.insert(30);
    s.insertbegin(10);
    s.insertend(40);
    s.insertpos(2, 20);
    s.printlist();
    s.deletebegin();
    s.deletepos(3);
    s.deleteend();
    s.printlist();
    return 0;
}