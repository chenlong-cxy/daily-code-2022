//函数模板
//#include <iostream>
//using namespace std;
//template<typename T>
//void Swap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
//	int a = 1, b = 2;
//	Swap(a, b);
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	double c = 1.1, d = 2.2;
//	Swap(c, d);
//	cout << "c = " << c << endl;
//	cout << "d = " << d << endl;
//	return 0;
//}

//显示类型转换
//#include <iostream>
//using namespace std;
//template<typename T>
//T Add(const T& a, const T& b)
//{
//	return a + b;
//}
//int main()
//{
//	int a = 1;
//	double b = 2.2;
//	cout << Add((double)a, b) << endl;
//	cout << Add<int>(a, b) << endl;
//	cout << Add<double>(a, b) << endl;
//	return 0;
//}

//非模板参数和同名的模板参数同时存在
//#include <iostream>
//using namespace std;
//template<typename T>
//T Add(const T& a, const T& b)
//{
//	return a + b;
//}
//int Add(const int& a, const int& b)
//{
//	return a + b;
//}
//int main()
//{
//	int a = 1, b = 2;
//	cout << Add(a, b) << endl;
//	cout << Add<int>(a, b) << endl;
//	return 0;
//}

//函数模板的匹配原则
//#include <iostream>
//using namespace std;
//template<class T1, class T2>
//T2 Add(const T1& a, const T2& b)
//{
//	return a + b;
//}
//int Add(const int& a, const int& b)
//{
//	return a + b;
//}
//int main()
//{
//	cout << Add(1, 2) << endl;
//	cout << Add(1, 2.2) << endl;
//	return 0;
//}

//非类型模板参数
//#include <iostream>
//using namespace std;
//template<class T, size_t N>
//class StaticArray
//{
//public:
//	size_t arraysize()
//	{
//		return N;
//	}
//private:
//	T _array[N];
//};
//int main()
//{
//	StaticArray<int, 100> a1;
//	cout << a1.arraysize() << endl;
//	StaticArray<int, 1000> a2;
//	cout << a2.arraysize() << endl;
//	return 0;
//}

//函数模板特化
//#include <iostream>
//#include <string>
//#include <typeinfo>
//using namespace std;
//template<class T>
//bool IsEqual(T x, T y)
//{
//	//cout << typeid(x).name() << endl;
//	return x == y;
//}
////template<>
////bool IsEqual<char*>(char* x, char* y)
////{
////	return strcmp(x, y) == 0;
////}
//bool IsEqual(char* x, char* y)
//{
//	return strcmp(x, y) == 0;
//}
//int main()
//{
//	/*string s1("2021dragon");
//	string s2("2021dragon");
//	cout << IsEqual(s1, s2) << endl;*/
//	char a1[] = "2021dragon";
//	char a2[] = "2021dragon";
//	cout << IsEqual(a1, a2) << endl; 
//	return 0;
//}

//类模板的全特化
//#include <iostream>
//using namespace std;
//template<class T1, class T2>
//class Dragon
//{
//public:
//	Dragon()
//	{
//		cout << "Dragon<T1, T2>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//template<>
//class Dragon<int, double>
//{
//public:
//	Dragon()
//	{
//		cout << "Dragon<int, double>" << endl;
//	}
//private:
//	int _d1;
//	double _d2;
//};
//int main()
//{
//	Dragon<int, int> d1;
//	Dragon<int, double> d2;
//	return 0;
//}

//类模板的偏特化1
//#include <iostream>
//using namespace std;
//template<class T1, class T2>
//class Dragon
//{
//public:
//	Dragon()
//	{
//		cout << "Dragon<T1, T2>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//template<class T2>
//class Dragon<int, T2>
//{
//public:
//	Dragon()
//	{
//		cout << "Dragon<int, T2>" << endl;
//	}
//private:
//	int _d1;
//	double _d2;
//};
//int main()
//{
//	Dragon<int, int> d1;
//	Dragon<double, double> d2;
//	return 0;
//}

//类模板的偏特化2
//#include <iostream>
//#include <typeinfo>
//using namespace std;
//template<class T1, class T2>
//class Dragon
//{
//public:
//	Dragon()
//	{
//		cout << "Dragon<T1, T2>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//template<class T1, class T2>
//class Dragon<T1*, T2*>
//{
//public:
//	Dragon()
//	{
//		cout << "Dragon<T1*, T2*>" << endl;
//		cout << typeid(_d1).name() << endl;
//	}
//private:
//	T1* _d1;
//	T2* _d2;
//};
//template<class T1, class T2>
//class Dragon<T1&, T2&>
//{
//public:
//	Dragon()
//	{
//		cout << "Dragon<T1&, T2&>" << endl;
//		cout << typeid(_d1).name() << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//int main()
//{
//	Dragon<int, int> d1;
//	Dragon<int&, int&> d2;
//	Dragon<int*, int> d3;
//	return 0;
//}

#include "Add.h"

int main()
{
	cout << Add(1, 2) << endl;
	cout << Add(1.1, 2.2) << endl;
	return 0;
}