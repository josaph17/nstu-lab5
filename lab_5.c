/*11. —ортировка Ухитра€Ф.»з массива путем однократного просмотра выбираетс€ последовательность элементов,
наход€щихс€ в пор€дке возрастани€, перенос€тс€ в выходной массив и замен€ютс€ во входном на У-1Ф. «атем
оставшиес€ элементы включаютс€ в полученную упор€доченную последовательность методом погружени€.*/
#include <stdio.h>
#include <locale.h>
#include<stdlib.h>
#define N 10

void ShowArray(int A[], int n);
void newWay(int in[], int out[], int n);
void ShiftR(char S[], int pos, int n);
void ShiftL(int S[], int pos, int n);


int main()
{
	setlocale(LC_ALL, "");
	//int Arr[N] = { 30, 11,25,1,4,0,8,3,2, 5 };
	int Arr[N] = { 30,11,25,1,6,26,20,5,7,3 };
	//int Arr[N] = { 1, 2,3,4,5,6,7,8,9,10 };
	int Arr2[N];
	printf("First array Arr: \n");
	ShowArray(Arr, N);
	newWay(Arr, Arr2,  N);
	printf("Second array Arr2: \n");
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
	out[0] = INT_MIN; //max sequence
	for (int i = 1; i <n+1; i++) /*<=n , +1 element*/
		out[i] = INT_MAX; /*follow array, element which finished max sequence*/

	for (int i = 0; i < n; i++)
		for (int j = 1; j < n+1; j++) /*running in out[] array*/
			if (out[j - 1] < in[i] && in[i] < out[j])
				out[j] = in[i];

	ShiftL(out, 1, 1); /*act to delete INT_MIN*/
 }	

void ShiftR(char S[], int pos, int n)
{
	int i = N-1;

	for (; i >= pos; i--)
	{
		S[i + n] = S[i];
	}
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