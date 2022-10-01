#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
//int main()
//{
//	string s("abcd");
//	sort(s.begin(), s.end());
//	int count = 0;
//	do
//	{
//		count++;
//		cout << s << endl;
//	} while (next_permutation(s.begin(), s.end()));
//	cout << count << endl;
//	return 0;
//}

//int main()
//{
//	string s("abcd");
//	sort(s.begin(), s.end(), greater<char>());
//	int count = 0;
//	do
//	{
//		count++;
//		cout << s << endl;
//	} while (prev_permutation(s.begin(), s.end()));
//	cout << count << endl;
//	return 0;
//}

//extern "C"
//{
//	void func(int a)
//	{
//		cout << a << endl;
//	}
//}
//int main()
//{
//	func(2);
//	return 0;
//}

extern "C"
{
	void func(int a)
	{
		cout << a << endl;
	}

	void func(double a)
	{
		cout << a << endl;
	}
}
int main()
{
	func(2);
	func(2.2);
	return 0;
}