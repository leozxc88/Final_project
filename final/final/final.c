#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(void)
{
	int i, j, ch1, ch, a=0, wrong, A = 0, B = 0, x, y, z, count = 0,try2,t;
	unsigned char try1[100],ans[10];
	srand(time(NULL));   /*�ü�*/
	for (t = 0; t < 10; t++)   /*��0~9��J��ans�}�C��*/
		ans[t] =0x30+t;     /*�r��0x30=0,0x31=1*/
	for (ch1 = 0; ch1 < 10; ch1++)/*������*/
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
			printf("�q�Ʀr�A�Ʀr�����ơA�Ʀr���m��OA�A�Ʀr���m���OB�A�вq�@��4��ƪ��Ʀr:");
			scanf_s("%s", try1,100);
			A = 0; B = 0,wrong=0;
			if (try1[4] !='\0')/*�ˬd�O�_��4���*/
				wrong++;
		//	for (j = 0; j < 4; j++)
		//	{
		//		printf("%d", try1[j]);
		//	}
			count++;
			for (i = 0; i < 4; i++)/*�ˬd�O�_�����ƿ�J*/
			{
				for (j = 0; j < 4; j++)
				{
					if (try1[i] == try1[j])
					{
						wrong++;
					}
				}
			}
			if (wrong > 4)/*���O��J�|�ӼƦr�άO���ƿ�J*/
			{
				printf("\n�п�J�|�Ӥ��P����!!\n\n");
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
		printf("\n���G��%dA%dB\n\n", A, B);
	}

	printf("���߲q��A�A�q�F%d��!\n", count);
	system("pause");
	return 0;
}
