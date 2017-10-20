#include"link_list.h"

int main()
{
	link_List<int> s;
	s.ins(10,10);
	s.ins(10,20);
	s.ins(10,30);
	s.ins(40,40);
	cout<<"第一次扫描输出："<<endl;
	s.prt();
	if(s.del(30))
		cout<<"删除元素30"<<endl;
	else
		cout<<"表中无30元素"<<endl;
	cout<<"第二次扫描输出："<<endl;
	s.prt();
	return 0;
}
