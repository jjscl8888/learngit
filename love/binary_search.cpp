#include<iostream>
#include<time.h>
#include<climits>
#include<stdlib.h>

using namespace std;

int  binary_search(int a[],int n,int  val)
{
	int left=0,right=n-1,mid=(left+right)/2;
	while(left<=right){
		if(a[mid]==val)return mid;
		if(a[mid]>val)right=mid-1;
		else left=mid+1;
		mid=(left+right)/2;
	}
	return -1;	
}

void Init_srand()
{
	srand(static_cast<int>(time(0)));
}

int get_number(int a,int b)
{
	return a+(b-a+1)*rand()%INT_MAX;
}
int main()
{
	int a[]={1,3,4,6,7,9,13};
	cout<<"find 7="<<binary_search(a,7,7)<<endl;
	
	return 0;
}
