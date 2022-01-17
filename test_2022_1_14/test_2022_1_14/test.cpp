#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//字符串相加
string add(string num1, string num2)
{
	int end1 = num1.size() - 1, end2 = num2.size() - 1;
	string RetStr;
	int next = 0; //进位
	while (end1 >= 0 || end2 >= 0)
	{
		int val1 = 0;
		if (end1 >= 0)
		{
			val1 = num1[end1] - '0';
			end1--;
		}
		int val2 = 0;
		if (end2 >= 0)
		{
			val2 = num2[end2] - '0';
			end2--;
		}

		int RetVal = val1 + val2 + next;
		if (RetVal > 9)
		{
			RetVal -= 10;
			next = 1;
		}
		else
			next = 0;

		RetStr += (RetVal + '0');
	}
	if (next == 1)
		RetStr += '1';
	reverse(RetStr.begin(), RetStr.end());
	return RetStr;
}
//字符串比较
int cmp(string num1, string num2)
{
	if ((num1.size() > num2.size()) || ((num1.size() == num2.size()) && (num1 > num2))) //num1大于num2
		return 1;
	else if ((num1.size() < num2.size()) || ((num1.size() == num2.size()) && (num1 < num2))) //num1小于num2
		return -1;
	else
		return 0;
}
//字符串相减
string substract(string num1, string num2)
{
	if (cmp(num1, num2) == -1) //num1小于num2
		return substract(num2, num1);

	int end1 = num1.size() - 1, end2 = num2.size() - 1;
	string RetStr;
	while (end1 >= 0 || end2 >= 0)
	{
		int val1 = 0;
		if (end1 >= 0)
		{
			val1 = num1[end1] - '0';
			end1--;
		}
		int val2 = 0;
		if (end2 >= 0)
		{
			val2 = num2[end2] - '0';
			end2--;
		}

		if (val1 < val2) //需要借位
		{
			int k = 0;
			while (num1[end1 - k] == '0')
			{
				num1[end1 - k] = '9';
				k++;
			}
			num1[end1 - k] = num1[end1 - k] - '1' + '0';
			val1 += 10;
		}
		int RetVal = val1 - val2;
		RetStr += (RetVal + '0');
	}
	reverse(RetStr.begin(), RetStr.end());
	size_t pos = RetStr.find_first_not_of('0');
	if (pos == string::npos)
	{
		return "0";
	}
	return RetStr.substr(pos);
}
//字符串相除
string division(string num1, string num2)
{
	if (cmp(num1, num2) == 1) //num1大于num2
		return division(num2, num1);

	string RetStr("0.");
	for (size_t i = 0; i < 101; i++)
	{
		if (num1 != "0")
			num1 += "0";
		int count = 0;
		while (cmp(num1, num2) != -1)
		{
			num1 = substract(num1, num2);
			count++;
		}
		char ch = count + '0';
		RetStr += ch;
	}
	return RetStr;
}
int main()
{
	int n = 400;
	string a = "1";
	string b = "1";
	while (n - 2)
	{
		string tmp = a;
		a = b;
		b = add(tmp, b);
		n--;
	}
	cout << a << endl;
	cout << b << endl;
	string ret = division(a, b);
	cout << ret << endl;
	cout << ret.size() - 2 << endl;
	return 0;
}
//n = 100
//0.61803398874989484820458683436563811772031274396379568575359185108829019869887522987627156252996318428
//n = 200
//0.61803398874989484820458683436563811772030917980576286213544862270526046281890244971288825799042314041
//n = 300
//0.61803398874989484820458683436563811772030917980576286213544862270526046281890244970720720418939113748
//n = 400
//0.61803398874989484820458683436563811772030917980576286213544862270526046281890244970720720418939113748

//answer
//0.6180339887498948482045868343656381177203091798057628621354486227052604628189024497072072041893911375