#ifndef SQ_STACK_H_
#define SQ_STACK_H_

#include<iostream>
using namespace std;

template<typename T>
class sq_Stack{
private:
	int mm;
	int top;
	T* s;
public:
	sq_Stack(int);
	void prt()const;
	int flag()const;
	void ins(T);
	T del();
	T pop()const;
};

template<typename T>
sq_Stack<T>::sq_Stack(int m)
{
	mm=m;
	s=new T[mm];
	top=0;
}

template<typename T>
void sq_Stack<T>::prt()const
{
	for(int i=0;i<top;i++)
		cout<<s[i]<<" ";
	cout<<endl;
}

template<typename T>
int sq_Stack<T>::flag()const
{
	if(top==mm)return -1;
	if(top==0)return 0;
	return 1;
}

template<typename T>
void sq_Stack<T>::ins(T x)
{
	if(top==mm)
	{
		cout<<"overflow"<<endl;
		return;
	}
	s[top]=x;
	top++;
}

template<typename T>
T sq_Stack<T>::del()
{
	if(!flag())
	{
		cout<<"underflow"<<endl;
		return	-1;
	}
	T temp=s[top-1];
	top--;
	return temp;
}

template<typename T>
T sq_Stack<T>::pop()const
{
	T temp=s[top-1];
	return temp;
}

#endif
