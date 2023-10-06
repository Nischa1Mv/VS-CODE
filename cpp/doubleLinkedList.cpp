#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	int data;
	node*right;
	node*left;
	node(){
		data=0;
		right=nullptr;
	    left=nullptr;
	}
	node(int data){
		this->data=data;
		this->left=nullptr;
		this->right=nullptr;
	}
};
class dll{
	public:
	node*head;
	dll(){head=nullptr;}
	 
	insert_head(int);
	insert_tail(int);
	insert_at(int,int);
	dellist(int);
};

void dll::dellist(int pos)
{
	int len=0;
	node*temp=head;
	while(temp!=nullptr){
		temp=temp->next;
		len++;
	}
	if(len<pos){cout<<"index out of 007"<<endl;return;	}
	temp=head;
	if(pos==1){
		head=head->right;
		head->left=nullptr;
		delete temp;
		return;
	}

	while(pos-->1){
		temp=temp->next;
	}
	temp->left->right=temp->right;
	if(pos!=len)
	temp->right->left=temp->left;
	delete temp;
}

void dll::insert_head(int data)
{
	node*p= new node(data);
	if(head==nullptr){
		head=p;
	}
	head->left=p;
	p->right=head;
	head=p;
}
void dll::insert_tail(int data)
{
	node*p= new node(data);
	if(head==nullptr){
		head=p;
	}
	node*temp=head;
	while(temp->next!=nullptr){
		temp=temp->next;
	}
	temp->right=p;
	p->left=temp;
}
void dll::insert_at(int pos, int data)
