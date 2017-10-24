#include"link_hash.h"

int hashf(int k);

int main()
{
	int a[12]={1,2,5,7,78,4,64,75,34,77,88,99};
	link_Hash<int> h(12);
	cout<<"原序列："<<endl;
	for(int i=0;i<12;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	
	for(int i=0;i<12;i++)
		h.ins(hashf,a[i]);
	
	cout<<"一次输出外链hash表中的关键字"<<endl;
	h.prt();
	/*
	for(int k=0;k<12;k++)
		cout<<(void*)h.search(hashf,a[k])<<" ";
	cout<<endl;
	*/	
	h.del(hashf,2);
	cout<<"delete 2"<<endl;
	h.prt();
	
	return 0;
}

int hashf(int k)
{return (k/3+1);}
