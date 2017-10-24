#ifndef LINK_HASH_H_
#define LINK_HASH_H_

#include<iostream>
using namespace std;

template<typename T>
struct LHnode{
	T key;
	LHnode* next;
};

template<typename T>
class link_Hash{
private:
	int NN;
	LHnode<T>** LH;
public:
	link_Hash(){NN=0;}
	link_Hash(int);
	~link_Hash();
	void prt();
	void ins(int (*f)(T),T);
	LHnode<T>* search(int (*f)(T),T);
	void del(int (*f)(T),T);
};

template<typename T>
link_Hash<T>::link_Hash(int m)
{
	int k;
	NN=m;
	LH=new LHnode<T>*[NN];
	for(k=0;k<NN;k++)
		LH[k]=NULL;
}

template<typename T>
link_Hash<T>::~link_Hash()
{
	LHnode<T>* p=NULL,*q=NULL;
	for(int i=0;i<NN;i++)
	{
		p=LH[i];
		while(p!=NULL)
		{
			q=p;
			p=p->next;
			delete q;
			q=NULL;
		}
	}
	delete[] LH;
}

template<typename T>
void link_Hash<T>::prt()
{
	LHnode<T>* p;
	for(int k=0;k<NN;k++)
	{
		p=LH[k];
		cout<<k+1<<" ";
		if(p==NULL)cout<<"<NULL>";
		else{
			while(p!=NULL){
				cout<<"---->";
				cout<<p->key;
				p=p->next;	
			}
		}
		cout<<endl;
	}
}

template<typename T>
void link_Hash<T>::ins(int (*f)(T),T x)
{
	LHnode<T>* p;
	int k=(*f)(x);
	p=new LHnode<T>;
	p->key=x;
	p->next=LH[k-1];
	LH[k-1]=p;
}

template<typename T>
LHnode<T>* link_Hash<T>::search(int (*f)(T),T x)
{
	int k=(*f)(x);
	LHnode<T>* p=LH[k-1];
	while((p!=NULL)&&(p->key!=x))p=p->next;
	return p;
}

template<typename T>
void link_Hash<T>::del(int (*f)(T),T x)
{
	int k=(*f)(x);
	LHnode<T> *p=LH[k-1],*q=NULL;
	while(p!=NULL&&p->key!=x){q=p;p=p->next;}
	if(p==NULL)
		cout<<"no find x"<<endl;
	else if(q!=NULL)q->next=p->next;
	else LH[k-1]=p->next;
}
#endif

