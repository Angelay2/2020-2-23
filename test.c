#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int cnt = 0;
int fib(int n){
	cnt++;
	if (n == 0){
		return 1;
	}
	else if (n == 1){
		return 2;
	}
	else{
		return fib(n - 1) + fib(n - 2);
	}
}
int main2(){
	fib(8);
	printf("%d\n", cnt);// 67
	system("pause");
	return 0;
}

int main3(){
	int x = 1;
	do{
		printf("%2d\n", x++);// 陷入死循环 全都为1
	} while (x--);

	system("pause");
	return 0;
}
//int main1(){
//	int x = 10;
//	int y = 10;
//	x = y = ++y;
//	printf("%d %d", x, y);// 11, 11
//
//	system("pause");
//	return 0;
//}
//	

int main4(){
	int i = 1;
	int j;
	j = i++;

	printf("%d %d\n", i, j);// 2 1
	system("pause");
	return 0;

}

int main5(){
	int i = 10;
	int j = 20;
	int k = 3;
	k *= i + j;// + 的优先级高于 *=

	printf("%d", k);// 90
	system("pause");
	return 0;
}

int a = 1;
void test(){
	int a = 2;
	a += 1;
}
int main6(){
	test();
	printf("%d\n", a);// 1 全局变量(换猫)

	system("pause");
	return 0;

}

// 如果至少有一个操作数为true, 则包含"||"运算符的表达式true