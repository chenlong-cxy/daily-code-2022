////���������
//#include <stdio.h>
//#include <string.h>
//
//void StringInGrid(int width, int height, const char* s)
//{
//	int i, k;
//	char buf[1000];
//	strcpy(buf, s);
//	if (strlen(s) > width - 2)buf[width - 2] = 0;
//
//	printf("+");
//	for (i = 0; i < width - 2; i++)printf("-");
//	printf("+\n");
//
//	for (k = 1; k < (height - 1) / 2; k++){
//		printf("|");
//		for (i = 0; i < width - 2; i++)printf(" ");
//		printf("|\n");
//	}
//
//	printf("|");
//	printf("%*s%s%*s", (width - strlen(buf) - 2) / 2, "", buf, (width - strlen(buf) - 2) / 2, ""); //���
//	printf("|\n");
//
//	for (k = (height - 1) / 2 + 1; k < height - 1; k++){
//		printf("|");
//		for (i = 0; i < width - 2; i++)printf(" ");
//		printf("|\n");
//	}
//
//	printf("+");
//	for (i = 0; i < width - 2; i++)printf("-");
//	printf("+\n");
//}
//int main()
//{
//	//printf("%*d\n", 6, 2022);
//	StringInGrid(20, 6, "abcd1234");
//	return 0;
//}

////���������
//#include <stdio.h>
//void test(int x[])
//{
//	int a = x[0] * 1000 + x[1] * 100 + x[2] * 10 + x[3];
//	int b = x[4] * 10000 * x[5] * 1000 + x[6] * 100 + x[7] * 10 + x[8];
//	if (a * 3 == b)printf("%d / %d\n", a, b);
//}
//void f(int x[], int k)
//{
//	int i, t;
//	if (k >= 9){
//		test(x);
//		return;
//	}
//	for (i = k; i < 9; i++){
//		t = x[k]; x[k] = x[i]; x[i] = t;
//		f(x, k + 1);
//		t = x[k]; x[k] = x[i]; x[i] = t; //���� //���
//	}
//}
//int main()
//{
//	int x[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	f(x, 0);
//	return 0;
//}

////�ӷ���˷�
//#include <iostream>
//using namespace std;
//int main()
//{
//	for (int i = 1; i <= 46; i++) //��һ���˺Ų��뵽����i�ĺ���
//	{
//		for (int j = i + 2; j <= 48; j++) //�ڶ����˺Ų��뵽����j����
//		{
//			if (i*(i + 1) - (i + i + 1) + j*(j + 1) - (j + j + 1) == 2015 - 1225)
//				cout << i << " " << j << endl;
//		}
//	}
//	return 0;
//}

////��������
//#include <iostream>
//using namespace std;
//int ans = 0;
//void f(int k, int cnt) //KΪ������ֵ0~12��cntΪ��ǰ����Ƶ�����0~13
//{
//	if (cnt > 13 || k > 13)
//		return;
//	if (k == 13 && cnt == 13) //��������ֵ���������Ҵ�ʱ����Ϊ13
//	{
//		ans++;
//		return;
//	}
//	for (int i = 0; i < 5; i++) //����ĳ������ֵ���ƣ�����û��0��Ҳ������1��2��3��4
//	{
//		f(k + 1, cnt + i);
//	}
//}
//int main()
//{
//	f(0, 0);
//	cout << ans << endl;
//	return 0;
//}

////�ƶ�����
//#include <iostream>
//#include <math.h>
//using namespace std;
//int main()
//{
//	int w, m, n;
//	cin >> w >> m >> n;
//	int mRow = (m - 1) / w, mCol = (m - 1) % w;
//	if (mRow % 2 == 1)
//	{
//		mCol = w - 1 - mCol;
//	}
//	int nRow = (n - 1) / w, nCol = (n - 1) % w;
//	if (nRow % 2 == 1)
//	{
//		nCol = w - 1 - nCol;
//	}
//	cout << abs(mRow - nRow) + abs(mCol - nCol) << endl;
//	return 0;
//}

