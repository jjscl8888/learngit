#ifndef LINK_LIST_H_
#define LINK_LIST_H_
#include<iostream>
using namespace std;
template<typename T>
struct node{
	T d;
	node* next;
	node(T value):d(value){next=NULL;}
};

template<typename T>
class link_List{
private:
	node<T> *head;
public:
	link_List();
	void prt()const;
	void ins(T,T);
	int del(T);
};

template<typename T>
link_List<T>::link_List()
{
	head=NULL;
}

template<typename T>
void link_List<T>::prt()const
{
	node<T>* p=head;
	while(p!=NULL){
		cout<<p->d<<" ";
		p=p->next;
	}
}

template<typename T>
void link_List<T>::ins(T x,T b)
{
	node<T> *q=NULL,*p;
	p=new node<T>(b);
	if(head==NULL)
	{head=p;return;}
	if(head->d==x)
	{p->next=head;head=p;return;}
	q=head;
	while(q->next!=NULL&&(q->next)->d!=x)
		q=q->next;
	p->next=q->next;
	q->next=p;
}

template<typename T>
int link_List<T>::del(T x)
{
	node<T> *q=NULL,*p=NULL;
	if(head==NULL)return 0;
	p=head;
	if(p->d==x){head=p->next;delete p;return 1;}
	while(p->next!=NULL&&(p->next)->d!=x)
		p=p->next;
	if(p->next==NULL)return 0;
	q=p->next;
	p->next=q->next;
	delete q;
	return 1;
}
#endif
