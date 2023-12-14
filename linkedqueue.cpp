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
        next = nullptr;
        this->data = data;
    }
};
class lqueue
{
    node *front, *rear;

public:
    lqueue() { front = rear = nullptr; }
    void enqueue(int);
    void dequeue();
    void display();
};
void lqueue ::enqueue(int data)
{
    node *p = new node(data);
    if (rear == nullptr)
    {
        front = rear = p;
        return;
    }
    rear->next = p;
    rear = p;
}
void lqueue ::dequeue()
{
    if (front == nullptr)
    {
        cout << "queue is empty" << endl;
        return;
    }
    node *temp = front;
    front = front->next;
    delete temp;
    if (front == nullptr)
    {
        rear = nullptr;
    }
}
void lqueue ::display()
{
    node *temp = front;
    while (temp != nullptr)
    {
        cout << temp->data << "->" << endl;
        temp = temp->next;
    }
}
int main()
{
    lqueue q;
    q.enqueue(10);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.display();
    return 0;
}