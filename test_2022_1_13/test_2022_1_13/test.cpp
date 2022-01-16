//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> MonthDay{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//int main()
//{
//	int year = 1777, month = 4, day = 30;
//	int num = 8113; //5343
//	int left = 1;
//	for (int i = 5; i <= 12; i++)
//	{
//		left += MonthDay[i];
//	}
//	num -= left;
//	cout << num << endl;
//	year++;
//	while (num > 365)
//	{
//		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//			num -= 366;
//		else
//			num -= 365;
//		year++;
//	}
//	cout << "year:" << year << endl;
//	cout << num << endl;
//	int i = 1;
//	month = 1;
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//		cout << "true" << endl;
//	while (num > 31)
//	{
//		num -= MonthDay[i];
//		i++;
//		month++;
//	}
//	cout << "month:" << month << endl;
//	cout << num << endl;
//	return 0;
//} //1799-7-16

//高斯日记
//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> MonthDay{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//int main()
//{
//	int year = 1777, month = 4, day = 30;
//	int num = 8113; //5343
//	for (int i = 0; i < num - 1; i++)
//	{
//		day++;
//		if (month == 2 && day > 28)
//		{
//			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//			{
//				if (day > 29)
//				{
//					month++;
//					day = 1;
//				}
//			}
//			else
//			{
//				month++;
//				day = 1;
//			}
//		}
//		else if (day > MonthDay[month])
//		{
//			month++;
//			day = 1;
//			if (month > 12)
//			{
//				year++;
//				month = 1;
//			}
//		}
//
//	}
//	cout << year << "-" << month << "-" << day << endl;
//	return 0;
//}//1799-7-16

//马虎的算式（枚举）
//#include <iostream>
//#include <vector>
//using namespace std;
//
////ab * cde = adb * ce
//int main()
//{
//	int count = 0;
//	for (int a = 1; a <= 9; a++)
//	{
//		for (int b = 1; b <= 9; b++)
//		{
//			for (int c = 1; c <= 9; c++)
//			{
//				for (int d = 1; d <= 9; d++)
//				{
//					for (int e = 1; e <= 9; e++)
//					{
//						if ((a != b) && (a != c) && (a != d) && (a != e) &&
//							(b != c) && (b != d) && (b != e) &&
//							(c != d) && (c != e) && 
//							(d != e))
//						{
//							int num1 = a * 10 + b;
//							int num2 = c * 100 + d * 10 + e;
//							int num3 = a * 100 + d * 10 + b;
//							int num4 = c * 10 + e;
//							if (num1*num2 == num3*num4)
//							{
//								printf("%d%d * %d%d%d = %d%d%d * %d%d = %d = %d\n",
//									a, b, c, d, e, a, d, b, c, e,
//									(a * 10 + b)*(c * 100 + d * 10 + e),
//									(a * 100 + d * 10 + b)*(c * 10 + e));
//								count++;
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	cout << count << endl; //1007
//	return 0;
//}//142


//第39级台阶（递归）
//#include <iostream>
//using namespace std;
//
//void f(int n, int step, int& count)
//{
//	if (n < 0)
//		return;
//	if (n == 0)
//	{
//		if (step % 2 == 0)
//			count++;
//		return;
//	}
//	f(n - 1, step + 1, count);
//	f(n - 2, step + 1, count);
//}
//int main()
//{
//	int step = 0, count = 0;
//	f(39, step, count);
//	cout << count << endl;
//	return 0;
//}

#include <iostream>
using namespace std;
//1 1  0
//2 2  1
//3 3  0+1  +1=2
//4 5  1+2  +0=2

//5 8  2+2  +0=4
//6 13 2+4  +1=7
//7 21 4+7  -1=10

//8 34 7+10 +0=17
//9 55 10+17+1=28
//10   17+28-1=44

int main()
{
	int step = 5;
	int first = 2;
	int second = 2;
	int third = 4;
	int num = 39;
	while (num - 4)
	{
		if (step % 3 == 2)
			third = first + second;
		else if (step % 3 == 0)
			third = first + second + 1;
		else
			third = first + second - 1;
		first = second;
		second = third;
		num--;
		step++;
	}
	cout << third << endl;
	return 0;
}


//#include<stdio.h>
//int main()
//{
//	int arr[50], a, i;
//	arr[1] = 0;
//	arr[2] = 1;
//	arr[3] = 2;
//	arr[4] = 2;
//	for (i = 5; i <= 10; i++)
//	{
//		a = (i - 2) % 3;
//		switch (a)
//		{
//		case 0:arr[i] = arr[i - 1] + arr[i - 2]; break;
//		case 1:arr[i] = arr[i - 1] + arr[i - 2] + 1; break;
//		case 2:arr[i] = arr[i - 1] + arr[i - 2] - 1; break;
//		}
//	}
//	printf("%d", arr[i - 1]);
//}
