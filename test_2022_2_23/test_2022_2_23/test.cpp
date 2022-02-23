#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template<class T>
struct TreeNode
{
	T _val;
	TreeNode<T>* _left;
	TreeNode<T>* _right;
	TreeNode(const T& val = 0)
		:_val(val)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

//template<class T>
//void Inorder(TreeNode<T>* proot)
//{
//	stack<TreeNode<T>*> st;
//	//1、将左路结点入栈
//	while (proot)
//	{
//		st.push(proot);
//		proot = proot->_left;
//	}
//	//依次取栈中结点
//	while (!st.empty())
//	{
//		//取出结点进行访问
//		TreeNode<T>* top = st.top();
//		st.pop();
//		cout << top->_val << " ";
//		//如果该结点的右子树不为空，则将右子树的左路结点入栈
//		if (top->_right != nullptr)
//		{
//			TreeNode<T>* cur = top->_right;
//			while (cur)
//			{
//				st.push(cur);
//				cur = cur->_left;
//			}
//		}
//	}
//}
template<class T>
vector<T> Inorder(TreeNode<T>* root)
{
	stack<TreeNode<T>*> st;
	vector<T> ret;
	TreeNode<T>* cur = root;
	while (cur || !st.empty())
	{
		//1、将左路结点入栈
		while (cur)
		{
			st.push(cur);
			cur = cur->_left;
		}
		//2、取栈顶结点并访问
		TreeNode<T>* top = st.top();
		st.pop();
		ret.push_back(top->_val);
		//3、准备访问其右子树
		cur = top->_right;
	}
	return ret;
}
int main()
{
	TreeNode<char> t1('A');
	TreeNode<char> t2('B');
	TreeNode<char> t3('C');
	TreeNode<char> t4('D');
	TreeNode<char> t5('E');
	TreeNode<char> t6('F');
	TreeNode<char> t7('G');
	TreeNode<char> t8('H');
	t1._left = &t2;
	t1._right = &t3;

	t2._left = &t4;
	t2._right = &t5;

	t3._right = &t6;

	t5._left = &t7;

	t6._left = &t8;

	vector<char> v = Inorder(&t1);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}