/*11. —ортировка Ухитра€Ф.»з массива путем однократного просмотра выбираетс€ последовательность элементов,
наход€щихс€ в пор€дке возрастани€, перенос€тс€ в выходной массив и замен€ютс€ во входном на У-1Ф. «атем
оставшиес€ элементы включаютс€ в полученную упор€доченную последовательность методом погружени€.*/
#include <stdio.h>
#include <locale.h>
#include<stdlib.h>
#define N 10

void ShowArray(int A[], int n);
void newWay(int in[], int out[], int n);
void ShiftL(int S[], int pos, int n); /*сдвиг хвоста влево*/


int main()
{
	setlocale(LC_ALL, "");
	int Arr[N] = { 30, 11,25,1,4,0,8,3,2, 5 };
	//int Arr[N] = { 1, 2,3,4,5,6,7,8,9,10 };
	int Arr2[N];
	printf("¬ходной массив Arr: \n");
	ShowArray(Arr, N);
	newWay(Arr, Arr2,  N);
	printf("¬ыходной массив Arr2: \n");
	ShowArray(Arr2, N);
	
	return 0;
}

void ShowArray(int A[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

void newWay(int in[], int out[], int n)
{
	out[0] = INT_MIN; //массив максимально длинной последовательности
	for (int i = 1; i <= n; ++i) /*<=n , т.к. 0-ой эл-т ставим INT_MAX , т.е. +1 эл-т*/
		out[i] = INT_MAX; /*заполн€ем массив, эл-т на который оканчиваетс€ максимально длинна€ последовательность*/

	for (int i = 0; i < n; i++)
		for (int j = 1; j <= n; j++)
			if (out[j - 1] < in[i] && in[i] < out[j])
				out[j] = in[i];

	ShiftL(out, 1, 1); /*сдвиг влево, чтобы убрать 1-ое значение INT_MIN*/
 }	

void ShiftL(int S[], int pos, int n)
{
	int i;

	for (i = pos; S[i] <=N+1; i++)
	{
		S[i - n] = S[i];
	}
	S[i - n] = S[i];
}