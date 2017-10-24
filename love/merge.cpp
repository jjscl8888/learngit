#include<iostream>
using namespace std;


template<typename T>
void merg(T p[],int low,int mid,int high,T a[])
{
	int i,j,k;
	i=low;j=mid+1;k=low;
	while(i<=mid&&j<=high)
	{
		if(p[i-1]<=p[j-1])	
			{a[k-1]=p[i-1];i++;}
		else
			{a[k-1]=p[j-1];j++;}
		k++;
	}
	if(i<=mid)
	{
		for(j=i;j<=mid;j++)
			{a[k-1]=p[j-1];k++;}
	}
	if(j<=high)
	{
		for(i=j;i<=high;i++)
			{a[k-1]=p[i-1];k++;}
	}
	
	for(i=low;i<=high;i++)
		p[i-1]=a[i-1];
}
template<typename T>
void merge(T p[],int n)
{
	int m,k,j,low,high,mid;
	T* a;
	a=new T[n];
	m=1;
	while(m<n)
	{
		k=2*m;
		for(j=1;j<=n;j+=k)
		{
			low=j;high=j+k-1;mid=j+m-1;
			if(high>n)high=n;
			if(mid<high)merg(p,low,mid,high,a);
		}
		m=k;
	}
	delete[] a;
}


int main()
{
	int a[8]={1,2,4,5,3,9,7,8};
	merge(a,8);
	for(int i=0;i<8;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
