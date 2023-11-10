#include <iostream>
using namespace std;
class node
{
    public:
    node *next;
    int data;
    public:
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
class stack
{
    public:
    node *top;
    stack()
    {
        top = nullptr;
    }

    void push(int data);
    void peek();
    void pop();
};

void stack::push(int data)
{
    node *p = new node(data);
    if (top == nullptr)
    {
        top = p;
    }
    p->next = top;
    top = p;
}

void stack::peek()
{
    if (top == nullptr)
    {
        cout << "list is empty" << endl;
    }
    cout<< top->data<<endl;
}
void stack::pop(){
    if(top==nullptr){
        cout<<"stack is empty"<<endl;
        return;
    }
    node*temp=top;
    top=top->next;
    delete(temp);
}
int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(40);
    s.pop();
    s.peek();
    s.push(30);
    s.peek();   
}
