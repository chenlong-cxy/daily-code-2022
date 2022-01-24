////奖劵数目
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int count = 0;
//	for (int i = 10000; i <= 99999; i++)
//	{
//		int a = i / 10000;
//		int b = i % 10000 / 1000;
//		int c = i % 10000 % 1000 / 100;
//		int d = i % 10000 % 1000 % 100 / 10;
//		int e = i % 10;
//		if ((a == 4) || (b == 4) || (c == 4) || (d == 4) || (e == 4))
//			count++;
//	}
//	int ret = 99999 - 10000 + 1 - count;
//	cout << ret << endl;
//	return 0;
//} //52488

//切面条
//1025

////李白打酒
//#include <iostream>
//using namespace std;
//void func(int jiu, int dian, int hua, int& count)
//{
//	if (dian == 0 && hua == 0 && jiu == 1)
//	{
//		count++;
//		return;
//	}
//	if(dian > 0)
//		func(jiu * 2, dian - 1, hua, count);
//	if(hua > 0)
//		func(jiu - 1, dian, hua - 1, count);
//}
//int main()
//{
//	int count = 0;
//	func(2, 5, 9, count);
//	cout << count << endl;
//	return 0;
//} //14

////史丰收速算
//#include <iostream>
//using namespace std;
//
//int ge_wei(int a)
//{
//	if (a % 2 == 0)
//		return (a * 2) % 10;
//	else
//		return (a * 2 + 5) % 10;
//}
//int jin_wei(char* mod)
//{
//	char* level[] = {
//		"142857",
//		"285714",
//		"428571",
//		"571428",
//		"714285",
//		"857142"
//	};
//	char buf[7];
//	buf[6] = '\0';
//	strncpy(buf, mod, 6);
//	int i;
//	for (i = 5; i >= 0; i--){
//		int tr = strcmp(level[i], buf);
//		if (tr < 0) return i + 1;
//		while (tr == 0){
//			mod += 6;
//			strncpy(buf, mod, 6);
//			tr = strcmp(level[i], buf);
//			if (tr < 0)return i + 1;
//			if (tr > 0)return i; //填空
//		}
//	}
//}
//void f(char* s)
//{
//	int head = jin_wei(s);
//	if (head > 0) printf("%d", head);
//
//	char* mod = s;
//	while (*mod){
//		int a = (*mod - '0');
//		int ge = ge_wei(a);
//		int jin = jin_wei(mod + 1);
//		int x = (ge + jin) % 10;
//		printf("%d", x);
//		mod++;
//	}
//	printf("\n");
//}
//int main()
//{
//	f("428571428571");
//	f("34553834937543");
//	return 0;
//}

////打印图形
//#include <iostream>
//#define N 70
//
//void f(char a[][N], int rank, int row, int col)
//{
//	if (rank == 1){
//		a[row][col] = '*';
//		return;
//	}
//	int w = 1;
//	int i;
//	for (i = 0; i < rank - 1; i++) w *= 2;
//	f(a, rank - 1, row, col + w / 2); //填空
//	f(a, rank - 1, row + w / 2, col);
//	f(a, rank - 1, row + w / 2, col + w);
//}
//int main()
//{
//	char a[N][N];
//	int i, j;
//	for (i = 0; i < N; i++){
//		for (j = 0; j < N; j++) a[i][j] = ' ';
//	}
//	f(a, 6, 0, 0);
//
//	for (i = 0; i < N; i++){
//		for (j = 0; j < N; j++) printf("%c", a[i][j]);
//		printf("\n");
//	}
//	return 0;
//}