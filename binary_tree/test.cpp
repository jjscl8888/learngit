#include"binary_tree.h"

int main()
{
	binary_Tree<int> b;
	b.create(-1);
	cout<<"前序序列："<<endl;
	b.pretrav();

	return 0;
}
