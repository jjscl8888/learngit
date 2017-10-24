#include<iostream>
using namespace std;

template<typename T>
struct Btnode{
	T d;
	Btnode* lchild;
	Btnode* rchild;
};

template<typename T>
class binary_Tree{
private:
	Btnode<T>* BT;
public:
	binary_Tree(){BT=NULL;}
	void create(T);
	void pretrav();
};

template<typename T>
void create1(Btnode<T>* p,int k,T end)
{
	Btnode<T>* q;
	T x;
	cin>>x;
	if(x!=end){
		q=new Btnode<T>;
		q->d=x;q->lchild=NULL;q->rchild=NULL;
		if(k==1)p->lchild=q;
		if(k==2)p->rchild=q;
		create1(q,1,end);
		create1(q,2,end);
	}
}
template<typename T>
void binary_Tree<T>::create(T end)
{
	Btnode<T>* p;
	T x;
	cin>>x;
	if(x==end)return;
	p=new Btnode<T>;
	p->d=x;
	p->lchild=NULL;
	p->rchild=NULL;
	BT=p;
	create1(p,1,end);
	create1(p,2,end);
}
template<typename T>
void pre(Btnode<T>* p)
{
	if(p){
		cout<<p->d<<" ";
		pre(p->lchild);
		pre(p->rchild);
	}
}

template<typename T>
void binary_Tree<T>::pretrav()
{
	Btnode<T>* q;
	q=BT;
	pre(q);
	cout<<endl;
}
