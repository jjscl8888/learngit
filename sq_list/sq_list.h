#ifndef SQ_LIST_H_
#define SQ_LIST_H_

#include<iostream>

using namespace std;

template<typename T>
class sq_LList{
private:
	int mm;
	int nn;
	T *v;
public:
	sq_LList(){mm=0;nn=0,v=NULL;}
	sq_LList(int);
	void prt()const;
	int flag()const;
	void ins(int ,T);
	void del(int);
};


template<typename T>
sq_LList<T>::sq_LList(int m)
{
	mm=m;
	v=new T[mm];
	nn=0;
}

template<typename T>
void sq_LList<T>::prt()const
{
	for(int i=0;i<nn;i++)
		cout<<v[i]<<" ";
	cout<<endl;
}

template<typename T>
int sq_LList<T>::flag()const
{
	if(nn==mm)return -1;
	if(nn==0)return 0;
	return 1;
}

template<typename T>
void sq_LList<T>::ins(int i,T x)
{
	if(nn==mm)
	{
	cout<<"overflow"<<endl;
	return;
	}
	if(i<1)i=1;
	if(i>nn)i=nn+1;
	for(int j=nn;j>=i;j--)
		v[j]=v[j-1];
	v[i-1]=x;
	nn++;
}

template<typename T>
void sq_LList<T>::del(int i)
{
	if(nn==0)
	{
	  cout<<"underflow"<<endl;
	  return ;
	}
	if(i<1||i>nn)
	{
		cout<<"Not find"<<endl;
		return;
	}
	for(int j=i;j<nn;j++)
		v[j-1]=v[j];
	nn--;
}
#endif
