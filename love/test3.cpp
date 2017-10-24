#include<iostream>
#include<algorithm>

using namespace std;

struct obj{
	int c;
	int k;
}p[10];

bool so(obj& a,obj& b)
{
	if(a.c!=b.c)
		return a.c>b.c;
	return a.k>b.k;
}

bool operator==(const obj& a,const obj& b)
{
	if(a.c==b.c&&a.k==b.k)
		return true;
	return false;
}

int main()
{
	int a,b;
	while(cin>>a>>b){
		int x=(a+b+abs(a-b))/2;
		int y=(a+b-abs(a-b))/2;
		p[0].c=x;
		p[0].k=y;
		for(int i=1;i<6;i++){
			cin>>a>>b;
			int x=(a+b+abs(a-b))/2;
			int y=(a+b-abs(a-b))/2;
			p[i].c=x;
			p[i].k=y;
		}
		sort(p,p+6,so);
		if(p[0]==p[1]&&p[2]==p[3]&&p[4]==p[5]&&p[0].c==p[3].c&&
		((p[5].c==p[0].k&&p[2].k==p[4].k)||(p[5].c==p[3].k&&p[0].k==p[5].k)))
			cout<<"posible"<<endl;
		else
			cout<<"imposible"<<endl;
	}
	return 0;
}
