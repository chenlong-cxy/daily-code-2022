//Z×ÖÐÎ±ä»»
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//class Solution {
//public:
//	string convert(string s, int numRows) {
//		if (numRows < 2)
//			return s;
//		vector<string> v(numRows);
//		size_t index = 0;
//		bool flag = false;
//		int row = 0;
//		while (index < s.size())
//		{
//			if (flag == false)
//			{
//				v[row] += s[index];
//				row++;
//				if (row == numRows)
//				{
//					flag = !flag;
//					row = numRows - 2;
//				}
//			}
//			else
//			{
//				v[row] += s[index];
//				row--;
//				if (row == -1)
//				{
//					flag = !flag;
//					row = 1;
//				}
//			}
//			index++;
//		}
//		string ret;
//		for (auto& e : v)
//		{
//			ret += e;
//		}
//		return ret;
//	}
//};
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows < 2)
			return s;
		vector<string> v(numRows);
		size_t index = 0;
		int flag = -1;
		int row = 0;
		while (index < s.size())
		{
			v[row] += s[index];
			index++;
			if (row == 0 || row == numRows - 1)
				flag = -flag;
			row += flag;
		}
		string ret;
		for (auto& e : v)
		{
			ret += e;
		}
		return ret;
	}
};
int main()
{
	cout << Solution().convert("AB", 1) << endl;
	return 0;
}