#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(void)
{
	int i, j, ch1, ch, a=0, wrong, A = 0, B = 0, x, y, z, count = 0,try2,t;
	unsigned char try1[100],ans[10];
	srand(time(NULL));   /*亂數*/
	for (t = 0; t < 10; t++)   /*把0~9輸入到ans陣列裡*/
		ans[t] =0x30+t;     /*字元0x30=0,0x31=1*/
	for (ch1 = 0; ch1 < 10; ch1++)/*換順序*/
	{
		a = rand() % 10;
		ch = ans[ch1];
		ans[ch1] = ans[a];
		ans[a] = ch;
	}
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d", ans[i]-0x30);
//	}
	while (A < 4)
	{
		do
		{
			printf("猜數字，數字不重複，數字對位置對是A，數字對位置錯是B，請猜一組4位數的數字:");
			scanf_s("%s", try1,100);
			A = 0; B = 0,wrong=0;
			if (try1[4] !='\0')/*檢查是否為4位數*/
				wrong++;
		//	for (j = 0; j < 4; j++)
		//	{
		//		printf("%d", try1[j]);
		//	}
			count++;
			for (i = 0; i < 4; i++)/*檢查是否有重複輸入*/
			{
				for (j = 0; j < 4; j++)
				{
					if (try1[i] == try1[j])
					{
						wrong++;
					}
				}
			}
			if (wrong > 4)/*不是輸入四個數字或是重複輸入*/
			{
				printf("\n請輸入四個不同的數!!\n\n");
			}

		} while (wrong > 4);

		for (x = 0; x < 4; x++)
		{
			if (try1[x] == ans[x])
			{
				A++;
			}
		}
		for (y = 0; y < 4; y++)
		{
			for (z = 0; z < 4; z++)
			{
				if (try1[y] == ans[z])
				{
					B++;
				}
			}
		}
		B = B - A;
		printf("\n結果為%dA%dB\n\n", A, B);
	}

	printf("恭喜猜對，你猜了%d次!\n", count);
	system("pause");
	return 0;
}
