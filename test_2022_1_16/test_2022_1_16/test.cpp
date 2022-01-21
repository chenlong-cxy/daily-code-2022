////Ç°×ºÅÐ¶Ï
//#include <iostream>
//using namespace std;
//
//char* prefix(char* haystack_start, char* needle_start)
//{
//	char* haystack = haystack_start;
//	char* needle = needle_start; //Ç°×º
//
//	while (*haystack && *needle)
//	{
//		if (*haystack++ != *needle++)
//			return NULL;
//	}
//	if (*needle)
//		return NULL;
//	return haystack_start;
//}
//int main()
//{
//	cout << prefix("abcd", "abc") << endl;
//	return 0;
//}

////Èý²¿ÅÅÐò
//#include <iostream>
//using namespace std;
//
//void sort3p(int* x, int len)
//{
//	int mod = 0;
//	int left = 0;
//	int right = len - 1;
//	while (mod <= right)
//	{
//		if (x[mod] < 0)
//		{
//			int t = x[left];
//			x[left] = x[mod];
//			x[mod] = t;
//			left++;
//			mod++;
//		}
//		else if (x[mod]>0)
//		{
//			int t = x[right];
//			x[right] = x[mod];
//			x[mod] = t;
//			right--;
//		}
//		else
//		{
//			mod++;
//		}
//	}
//}
//int main()
//{
//	int arr[] = {25, 18, -2, 0, 16, -5, 33, 21, 0, 19, -16, 25, -3, 0};
//	sort3p(arr, sizeof(arr)/sizeof(int));
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

////´íÎóÆ±¾Ý
//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//using namespace std;
//
//int main()
//{
//	int N = 0;
//	cin >> N;
//	getchar();
//	vector<int> v;
//	for (int i = 0; i < N; i++)
//	{
//		string s;
//		getline(cin, s);
//		int start = 0;
//		int end = s.find(' ');
//		while (end != string::npos)
//		{
//			string tmp = s.substr(start, end - start);
//			int data = stoi(tmp);
//			v.push_back(data);
//			start = end + 1;
//			end = s.find(' ', start);
//		}
//		string tmp = s.substr(start, end - start);
//		int data = stoi(tmp);
//		v.push_back(data);
//	}
//	map<int, int> m;
//	for (auto e : v)
//	{
//		m[e]++;
//	}
//	auto it = m.begin();
//	int prev = it->first;
//	it++;
//	while (it != m.end())
//	{
//		if (it->first != prev + 1)
//		{
//			cout << it->first - 1 << " ";
//			break;
//		}
//		prev++;
//		it++;
//	}
//	for (auto e : m)
//	{
//		if (e.second == 2)
//			cout << e.first << endl;
//	}
//	return 0;
//}

////·­Ó²±Ò
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string s1, s2;
//	cin >> s1 >> s2;
//	int start = -1, end = -1;
//	int ret = 0;
//	for (int i = 0; i < s1.size(); i++)
//	{
//		if (s1[i] != s2[i])
//		{
//			if (start == -1)
//			{
//				start = i;
//			}
//			else
//			{
//				end = i;
//				ret += end - start;
//				start = -1;
//			}
//		}
//	}
//	cout << ret << endl;
//	return 0;
//}