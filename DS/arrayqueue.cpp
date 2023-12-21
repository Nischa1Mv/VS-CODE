#include <iostream>
#define MAX 400
using namespace std;
class queue
{
    int front, rear;
    int a[MAX];

public:
    queue()
    {
        front = rear = -1;
    }
    void enqueue(int data);
    void dequeue();
    void pfront();
    void display();
};
void queue::enqueue(int data)
{
    if (rear == MAX - 1)
    {
        cout << "queue is full" << endl;
        return;
    }
    if (rear == -1)
    {
        rear = front = 0;
        a[rear] = data;
        return;
    }
    rear += 1;
    a[rear] = data;
}
void queue::dequeue()
{
    if (front == -1)
    {
        cout << "queue is empty" << endl;
        return;
    }
    if (front = rear)
    {
        cout << a[front] << "is removed " << endl;
        front = rear = -1;
        return;
    }
    cout << a[front] << " is removed" << endl;
    front += 1;
}
void queue::pfront()
{
    if (front == -1)
    {
        cout << "queue is empty" << endl;
        return;
    }
    cout << a[front] << endl;
}
void queue::display()
{
    if (front == -1 && rear == -1)
    {
        cout << "queue is empty" << endl;
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(40);
    q.dequeue();
    q.pfront();
    q.enqueue(50);
    q.display();
    return 0;
}
