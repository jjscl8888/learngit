#include<iostream>
#include<vector>

using namespace std;
bool search(int a[],int len,int x)
{
	for(int i=0;i<len;i++)
		if(a[i]==x)return true;
	return false;
}

bool half_search(int a[],int len,int x)
{
	int left=0,right=len-1,half=(left+right)/2;
	while(left<right)
	{
		if(a[half]==x)return true;
		else if(a[half]<x)
		{
			left=half;
		}else
			right=half;
		half=(left+right)/2;
	}		
	return false;
}
int main()
{
	int a[]={1,3,5,6,7,9,10};
	cout<<boolalpha;
	cout<<"5 in "<<half_search(a,9,5)<<endl;
	return 0;
}
