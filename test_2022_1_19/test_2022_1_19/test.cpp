////��ֵķ�ʽ
//#include <iostream>
//using namespace std;
//int gcb(int a, int b) //���Լ��
//{
//	if (b == 0)
//		return a;
//	return gcb(b, a%b);
//}
//int main()
//{
//	int ans = 0;
//	for (int a = 1; a <= 9; a++)
//	{
//		for (int b = 1; b <= 9; b++)
//		{
//			if (a == b)
//				continue;
//			for (int c = 1; c <= 9; c++)
//			{
//				for (int d = 1; d <= 9; d++)
//				{
//					if (c == d)
//						continue;
//					int g1 = gcb(a*c, b*d);
//					int g2 = gcb(a * 10 + c, b * 10 + d);
//					if ((a*c / g1 == (a * 10 + c) / g2) && (b*d / g1 == (b * 10 + d) / g2))
//						ans++;
//				}
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//} //14

////��������
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//bool check(vector<int>& v)
//{
//	int a = 1 + v[0] + v[3] + v[5];
//	int b = 1 + v[1] + v[4] + v[8];
//	int c = v[5] + v[6] + v[7] + v[8];
//	int d = 8 + v[0] + v[1] + v[2];
//	int e = 8 + v[3] + v[6] + 3;
//	int f = 3 + v[7] + v[4] + v[2];
//	if (a == b&&b == c&&c == d&&d == e&&e == f)
//		return true;
//	return false;
//}
//int main()
//{
//	vector<int> v{ 2, 4, 5, 6, 7, 9, 10, 11, 12 };
//	do
//	{
//		if (check(v))
//		{
//			break;
//		}
//	} while (next_permutation(v.begin(), v.end()));
//	cout << v[3] << endl;
//	return 0;
//} //10

//���ϸ�ð
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int data = 0;
		cin >> data;
		v.push_back(data);
	}
	int pos = v[0];
	int count1 = 0, count2 = 0;
	if (pos > 0) //��ð����������
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			if (v[i] < 0 && pos < -v[i]) //����������λ��pos�ұߵ����϶�����Ⱦ
				count1++;
		}
		if (count1 != 0) //�д�������������б���Ⱦ��
		{
			for (size_t i = 0; i < v.size(); i++)
			{
				if (v[i] > 0 && pos > v[i]) //����������λ��pos��ߵ����϶�����Ⱦ
					count1++;
			}
		}
	}
	else //��ð����������
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			if (v[i] > 0 && -pos > v[i]) //����������λ��pos��ߵ����϶�����Ⱦ
				count2++;
		}
		if (count2 != 0) //�д������ҵ������б���Ⱦ��
		{
			for (size_t i = 0; i < v.size(); i++)
			{
				if (v[i] < 0 && -pos < -v[i]) //����������λ��pos�ұߵ����϶�����Ⱦ
					count2++;
			}
		}
	}
	cout << count1 + count2 + 1 << endl;
	return 0;
}