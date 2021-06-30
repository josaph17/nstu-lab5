/*11. ���������� ��������.�� ������� ����� ������������ ��������� ���������� ������������������ ���������,
����������� � ������� �����������, ����������� � �������� ������ � ���������� �� ������� �� �-1�. �����
���������� �������� ���������� � ���������� ������������� ������������������ ������� ����������.*/
#include <stdio.h>
#include <locale.h>
#define N 10

void ShowArray(int A[], int n);
void MaxPosl(int A[], int A2[], int n);
//void CopyArray(int A[], int A2[], int n);
void MaxPosl(int A[], int A2[], int n);
void LazySort(int in[], int out[], int n);

int main()
{
	setlocale(LC_ALL, "");
	int Arr[N] = { 30, 11,25,1,4,0,8,3,2, 5 };
	int Arr2[N];
	printf("������� ������ Arr: \n");
	ShowArray(Arr, N);
	/*CopyArray(Arr, Arr2, N);
	ShowArray(Arr2, N);*/
	//MaxPosl(Arr, Arr2, N);
	LazySort(Arr, Arr2, N);
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

void MaxPosl(int A[], int A2[], int n)
{
	int max, k, num, x;
	//max - ����� �������� ����. ����-��
	/*� i-��-� ���������� ���� ������� ����. ������-��, ���� �� ������� �� ����� ��� ���� � ������ ��-�*/

	k = max = 0; /*����� ��������� ������������������ ��� ������ ������������������*/
	for (int i = 0; i < N - 1; i++) /*������� ������*/
	{
		if (A[i + 1] > A[i]) /*���� ��������� ����� ������ �����������*/
		{
			k++; /*����� ���� ������� �����-�, ����������, ����� �� 1 ������*/
		}
		else
			k = 0;

		if (k > max) //max - ���� 
		{
			max = k;
			num = i + 1;
		}
	}
	max++;
	x = num - max + 1;
	printf("���������� ������������ ���������������������: \n");

	for (int i = x; i < max + x; i++)
	{
		printf("%d ", A[i]);
	}
}

//void CopyArray(int A[], int A2[], int n)
//{
//	int p = 0;
//	for (int i = 0; i < n; i++)
//	{
//		A2[p] = A[i];
//		p++;
//	}
//}
void LazySort(int in[], int out[], int n)
{
	int i, j = 0, c = in[0]=out[0]; //��������� ���������� ��� ������ � in[]
	for (i = 1; i < n; i++)
	{
		if (c < in[i])
		{
			c = in[i], out[j++] = in[i], in[i]=-1;
		}
	}
}