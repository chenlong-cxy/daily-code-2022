#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	int translateNum(int num) {
		string s = to_string(num);
		int a = 1, b = 1;
		int len = s.size();
		for (int i = 0; i <= len - 2; i++)
		{
			string tmp = s.substr(i, 2);
			int n = stoi(tmp);
			int c = (n >= 10 && n <= 25) ? (a + b) : b;
			a = b;
			b = c;
		}
		return b;
	}
};
int main()
{
	cout << Solution().translateNum(1) << endl;
	return 0;
}