#include <iostream>
#define max 4000
using namespace std;

class stack
{
    int top;

public:
    int s[max];
    stack() { top = -1; }
    void pop();
    void push(int data);
    bool isempty();
    void peek();
    void show();
};

void stack::push(int data)
{
    if (top >= max - 1)
    {
        cout << "overflow" << endl;
        return;
    }
    s[++top] = data;
    cout << data << " is pushed into stack" << endl;
}

void stack::pop()
{
    if (top == -1)
    {
        cout << "stack is empty" << endl;
        return;
    }
    cout << s[top] << " is deleted" << endl;
    top--;
}

bool stack::isempty()
{
    return (top == -1);
}

void stack::peek()
{
    if (top == -1)
    {
        cout << "stack is empty" << endl;
        return;
    }
    cout << s[top] << endl;
}

void stack::show()
{
    while (!isempty())
    {
        cout << s[top--] << " " << endl;
    }
}

int main()
{
    stack s;
    s.push(10);
    s.peek();
}
