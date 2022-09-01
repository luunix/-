#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int input = 0;
	printf("加入比特后你会好好学吗？\
            (会:1/不会  0)\n");
	scanf("%d", &input);
	if (1 == input)
	{
		printf("可以拿到好office\n");

	}
	else
	{
		printf("你可以在比特门口卖红薯");
	}

	return 0;
}
