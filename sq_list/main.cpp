#include"sq_list.h"

int main()
{
	sq_LList<double> s1(100);
	cout<<"第一次输出顺序列表 s1"<<endl;
	
	s1.prt();
	s1.ins(0,1.5);
	s1.ins(1,2.5);
	s1.prt();
	return 0;
}
