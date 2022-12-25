#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	string reverseWords(string s) {
		vector<string> v;
		size_t a = s.find_first_not_of(' ');
		if (a == string::npos)
			return "";
		size_t b = s.find_last_not_of(' ');
		s = s.substr(a, b - a + 1);
		size_t start = 0;
		size_t pos = s.find(' ', start);
		while (pos != string::npos)
		{
			string sub = s.substr(start, pos - start);
			v.push_back(sub);
			start = pos + 1;
			while (start < s.size() && s[start] == ' ')
				start++;
			pos = s.find(' ', start);
		}
		string sub = s.substr(start);
		v.push_back(sub);
		string ret;
		for (int i = (int)v.size() - 1; i >= 1; i--)
		{
			ret += v[i];
			ret += " ";
		}
		ret += v[0];
		return ret;
	}
};
int main()
{
	cout << Solution().reverseWords("  hello world!  ") << endl;
	return 0;
}