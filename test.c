#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

// ���������һ��������Ϊtrue, �����"||"������ı��ʽtrue
// C���Թ涨, ��һ��Դ������, main������λ�� => ��������
// һ��CԴ�������һ�������������
// һ��CԴ����������һ��main����
// C����Ļ�����ɵ�λ�Ǻ���
// C���Ա���û������������

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
		printf("%2d\n", x++);// ������ѭ�� ȫ��Ϊ1
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
	k *= i + j;// + �����ȼ����� *=

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
	printf("%d\n", a);// 1 ȫ�ֱ���(��è)

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
	y = x + 3 / 2;// ���ȼ�/����-����=
	printf("%f\n", y);// 3.000000

	system("pause");
	return 0;

}

int main9(){
	int x, y;
	for (x = 0, y = 0; (y = 123) && (x < 4); x++){
		printf("1\n");// ѭ��4�� a && b��a��bͬʱΪtrue �ŷ��� true�� ���򷵻�false
	}
	system("pause");
	return 0;
}

int main10(){
	int year = 1000, *p = &year;
	*p += 1;
	(*p)++;
	++(*p);
	*p++;// 1000 ++���ȼ�����* Ϊ��++ ʵ��Ϊ*p
	printf("%d\n", year);

	system("pause");
	return 0;
}

// λ������ ֻҪһλΪ1 ��Ϊ1 
int main11(){
	printf("%d", 11 | 10); // 1011 | 1010 => 1011 = 11
	// ���Ϊ 11
	system("pause");
	return 0;
}

//int main12(){
//	char a;
//	int b;
//	float c;
//	double d;
//
//	a * b + d - c;// һ·���� => ���Ϊdouble��
//
//	system("pause");
//	return 0;
//}

// ����С������
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

// �����ַ���
// I love you => you love I
// �Ƚ���������ĸҲ�����������ӵķ�ת => uoy evol I
// �������ת����
void reverse(char* start, char* end){
	while (start < end){
		char tmp = *start;
		*start = *end;// u �滻 I
		*end = tmp;// I �滻 u

		start++;// startָ��' '
		end--;// endָ�� 'u'
	}
}
int main(){
	char input[100];

	// ע�ⲻ��ʹ��scanf, scanf�����ո�, һ��������վͽ�����
	gets(input);

	// ��ת��������
	reverse(input, input + strlen(input) - 1);

	// �����ת����
	char* start = input;// ��ʼ��ַָ��'u'
	
	// you��ɺ� ָ��ָ��'e', ѭ���������� ������ת��һ������ love
	while (*start){
		char* end = start;// endָ��'u'

		while (*end != ' ' && *end){
			end++;// endָ��'o',���ε���ָ��'y',' '
		}// "uoy " end-1 ָ��'u' 
		// ��������ת��һ������uoy => you 
		reverse(start, end - 1);//  ��һ������ ��Ϊ"you evol I"
		// ��ʱstartָ��'y'

		if (*end){
			start = end + 1;// start ָ��'e'
		}
		else{
			start = end;
		}
	}
	printf("%s", input);
	system("pause");
	return 0;
}