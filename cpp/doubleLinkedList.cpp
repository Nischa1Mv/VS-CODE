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
	 
    void insert_head(int);
	void insert_tail(int);
	void insert_at(int,int);
	void dellist(int);
	void printlist();
};

void dll::dellist(int pos)
{
	int len=0;
	node*temp=head;
	while(temp!=nullptr){
		temp=temp->right;
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
		temp=temp->right;
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
	while(temp->right!=nullptr){
		temp=temp->right;
	}
	temp->right=p;
	p->left=temp;
}
void dll::insert_at(int pos, int data)
{
	if(pos==1){
		insert_head(data);
		return;
	}
	int len=0;
	node*temp=head;
	while(temp!=nullptr){
		temp=temp->right;
		len++;
	}
	if(pos==len){
		insert_tail(data);
		return;
	}
	node*p= new node(data);
	if(head==nullptr){
		head=p;
		return;
	}
	
	temp=head;
	while(pos-->2){
		temp=temp->right;
	}
	p->right=temp->right;
	p->right->left=p;
	p->left=temp;
	temp->right=p;
	
}
void dll::printlist(){
	node*temp=head;
	while(temp!=nullptr){
		cout<<temp->data<<"<=>";
		temp=temp->right;
	}
	cout<<"NULL"<<endl;
}
int main(){
	insert_head(10);
	insert_tail(30);
	insert_tail(40);
	insert_tail(50);
	insert_tail(60);
	insert_at(2,20);
	printlist();
	
}
