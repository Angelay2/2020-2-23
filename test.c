#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

// 如果至少有一个操作数为true, 则包含"||"运算符的表达式true
// C语言规定, 在一个源程序中, main函数的位置 => 可以任意
// 一个C源程序可由一个或多个函数组成
// 一个C源程序必须包含一个main函数
// C程序的基本组成单位是函数
// C语言本身没有输入输出语句

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

int main7(){
	int a = 0, c = 0;
	do{
		--c;
		a = a - 1;
	} while (a > 0);
	printf("%d ", c);// -1

	system("pause");
	return 0;
}

int main8(){
	double x;
	double y;
	x = 2;
	y = x + 3 / 2;// 优先级/高于-高于=
	printf("%f\n", y);// 3.000000

	system("pause");
	return 0;

}

int main9(){
	int x, y;
	for (x = 0, y = 0; (y = 123) && (x < 4); x++){
		printf("1\n");// 循环4次 a && b：a和b同时为true 才返回 true， 否则返回false
	}
	system("pause");
	return 0;
}

int main10(){
	int year = 1000, *p = &year;
	*p += 1;
	(*p)++;
	++(*p);
	*p++;// 1000 ++优先级高于* 为后++ 实际为*p
	printf("%d\n", year);

	system("pause");
	return 0;
}

// 位或运算 只要一位为1 就为1 
int main11(){
	printf("%d", 11 | 10); // 1011 | 1010 => 1011 = 11
	// 结果为 11
	system("pause");
	return 0;
}

//int main12(){
//	char a;
//	int b;
//	float c;
//	double d;
//
//	a * b + d - c;// 一路提升 => 结果为double型
//
//	system("pause");
//	return 0;
//}

// 求最小公倍数
int main12(){
	int a, b;
	scanf("%d%d", &a, &b);
	int i = 1;
	while ((a * i) % b != 0){
		i++;
	}
	printf("%d\n", a * i);

	system("pause");
	return 0;
}

// 倒置字符串
// I love you => you love I
// 先进行所有字母也就是整个句子的翻转 => uoy evol I
// 再逐个翻转单词
void reverse(char* start, char* end){
	while (start < end){
		char tmp = *start;
		*start = *end;// u 替换 I
		*end = tmp;// I 替换 u

		start++;// start指向' '
		end--;// end指向 'u'
	}
}
int main(){
	char input[100];

	// 注意不能使用scanf, scanf遇到空格, 一次输入接收就结束啦
	gets(input);

	// 翻转整个句子
	reverse(input, input + strlen(input) - 1);

	// 逐个翻转单词
	char* start = input;// 起始地址指向'u'
	
	// you完成后 指针指到'e', 循环调到这里 继续翻转下一个单词 love
	while (*start){
		char* end = start;// end指向'u'

		while (*end != ' ' && *end){
			end++;// end指向'o',依次递增指向到'y',' '
		}// "uoy " end-1 指向'u' 
		// 接下来翻转第一个单词uoy => you 
		reverse(start, end - 1);//  第一遍完了 变为"you evol I"
		// 此时start指向'y'

		if (*end){
			start = end + 1;// start 指向'e'
		}
		else{
			start = end;
		}
	}
	printf("%s", input);
	system("pause");
	return 0;
}