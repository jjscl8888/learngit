#include"sq_stack.h"

int main()
{
	sq_Stack<int> s(10);
	s.ins(50);
	s.ins(60);
	s.ins(70);
	s.ins(80);
	s.ins(90);
	cout<<"输出栈顶元素："<<endl;
	s.prt();
	cout<<"栈顶元素："<<s.pop()<<endl;
	cout<<"退栈元素："<<endl;
	cout<<s.del()<<endl<<s.del()<<endl<<s.del()<<endl;
	cout<<"再次输出元素："<<endl;
	s.prt();
	return 0;
}
