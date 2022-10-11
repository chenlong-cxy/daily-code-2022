#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> us(wordDict.begin(), wordDict.end());
		vector<bool > v(s.size() + 1, false);
		v[0] = true;
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (v[j] && us.find(s.substr(j, i - j)) != us.end())
				{
					v[i] = true;
					break;
				}
			}
		}
		return v[v.size() - 1];
	}
};
int main()
{
	vector<string> v = { "leet", "code" };
	cout << Solution().wordBreak("leetcode", v) << endl;
	return 0;
}