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
class cll
{
    node *head;

public:
    cll() { head = nullptr; }

    void insert_begin(int);
    void insert_end(int);
    void insert_at(int, int);
    void delete_head();
    void delete_tail();
    void delete_at(int);
    void printlist();
};
void cll::insert_end(int data)
{
    node *p = new node(data);
    if (head == nullptr)
    {
        head = p;
        head->next = head;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = p;
    p->next = head;
}
void cll::insert_begin(int data)
{
    node *p = new node(data);
    if (head == nullptr)
    {
        head = p;
        head->next = head;
        return;
    }
    node *temp = head;
    temp->next = p;
    p->next = head;
    head = p;
}
void cll::insert_at(int pos, int data)
{
    node *temp = head;
    // finding length
    int len = 0;
    while (temp != head)
    {
        temp = temp->next;
        len++;
    }
    // checks out of range
    if (len < pos)
    {
        cout << "index out of range" << endl;
        return;
    }
    // pos at 1
    if (pos == 1)
    {
        insert_begin(data);
    }
    // pos at end
    if (len == pos)
    {
        insert_end(data);
        return;
    }
    node *p = new node(data);
    if (head == nullptr)
    {
        head = p;
        head->next = head;
        return;
    }
    temp = head;
    while (pos-- > 2)
    {
        temp = temp->next;
    }
    p->next = temp->next;
    temp->next = p;
}
void cll ::delete_head()
{
    if (head == nullptr)
    {
        cout << "list is empty";
        return;
    }
    node *temp1 = head;
    head = head->next;
    node *temp = head;
    while (temp->next != temp1)
    {
        temp = temp->next;
    }
    temp->next = head;
    delete (temp1);
}
void cll ::delete_tail()
{
    if (head == nullptr)
    {
        cout << "list is empty";
        return;
    }
    node *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    node *temp1 = temp->next;
    delete (temp1);
    temp->next = head;
}
void cll ::delete_at(int pos)
{
    if (head == nullptr)
    {
        cout << "list is empty" << endl;
        return;
    }
    node *temp = head;
    int len = 0;
    while (temp != head)
    {
        temp = temp->next;
        len++;
    }
    temp = head;
    while (pos-- > 1)
    {
        temp = temp->next;
    }
    node *temp1 = temp->next;
    temp->next = nullptr;
    free(temp1);
    delete (temp1);
}
void cll::printlist()
{

    if (head == nullptr)
    {
        cout << "list is empty" << endl;
        return;
    }
    node *temp = head;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main()
{
    cll c;
    c.insert_begin(50);
    c.insert_end(40);
    c.insert_end(30);
    c.insert_end(20);
    c.insert_end(10);
    c.delete_head();
    c.delete_tail();
    c.printlist();
}
