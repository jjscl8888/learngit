#include<iostream>
#include<string>

using namespace std;

bool is(string s,string t)
{
	if(t==s)return true;
	int len=s.size();
	if(len>t.size())return false;
	int ind=0;
	for(int i=0;i<len;i++)
	{
		ind=t.find(s[i],ind);
		if(ind==string::npos)return false;
	}
	return true;
}
int main()
{
	string t,s;
	cin>>t>>s;
	cout<<is(s,t)<<endl;
	return 0;
}
