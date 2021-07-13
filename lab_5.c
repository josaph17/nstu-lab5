/*11. ���������� ��������.�� ������� ����� ������������ ��������� ���������� ������������������ ���������,
����������� � ������� �����������, ����������� � �������� ������ � ���������� �� ������� �� �-1�. �����
���������� �������� ���������� � ���������� ������������� ������������������ ������� ����������.*/
#include <stdio.h>
#include <locale.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 8

void ShowArray(int A[], int n);
int	F7(int in[], int n);
int habrLength(int in[], int n);
int ceilIndex(int subsequence[], int startLeft, int startRight, int key);

int main()
{
	setlocale(LC_ALL, "");
	//int Arr[N] = { 30, 11,25,1,4,0,8,3,2, 5 };
	int Arr[N] = { 5, 10,6,12,3,24,7,8};
	//int Arr[N] = { 0, 0,25,1,25,0,8,25,0, 0 };
	//int Arr[N] = {0,8,3,2,5 };
	printf("First array Arr: \n");
	ShowArray(Arr, N);
    int length = habrLength(Arr, N);
    printf("����� ����������� ������� ������-�: %d\n", length);	
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

int	F7(int in[], int n)
{
	int i, j, m, s, t;
	i = 0, t=0;
	int digit = in[i];
	for (s = 1; i < n - 1; i++)
	{
		for (j = i + 1, m = 1; j < n; j++)
			if (digit < in[j])
				{
				t = j;
				digit = in[j];
				m++;
				}
		if (m > s)
			s = m;
	}
	return s;
}

int habrLength(int in[], int n) 
{
    /*���� ������� ������ ������������� �������� � �������, ��������� ������� � �����, 
    ����� ��������� ������� ������ ������������� � ���� �������*/
    if (n <= 1) 
        return 1;

    int lis_length = 1; /*���� -1 , �� ����������� ����� ������������������ 1*/

    int minElementForLength[N];
    int indexes[N];

    for (int i = 0; i < n; ++i) 
        minElementForLength[i] = INT_MAX;

    minElementForLength[0] = in[0];
    indexes[0] = 1; //���� 0, ����� ����������� ������ 1

    for (int i = 1; i < n; ++i) 
    {
        indexes[i] = ceilIndex(minElementForLength, 0, i, in[i]);

        if (lis_length < indexes[i]) 
            lis_length = indexes[i];
    }
    printf("������ indexes �����: \n");
    ShowArray(indexes, N);  
    printf("������  minElementForLength �����: \n");
    ShowArray(minElementForLength, N);

       return lis_length;
}

int ceilIndex(int minElementForLength[], int startLeft, int startRight, int key) 
/*�-� ������� ���������� ������������ ���-�� ��-�, ������ ���� ����� ����� ���� ������ �� �����������*/
{

    int mid = 0;
    int left = startLeft; /*������ ��� ��-� �������*/
    int right = startRight; /*������ ������������� �������� ������*/
    int ceilIndex = 0;
    bool ceilIndexFound = false;

    for (mid = (left + right) / 2; left <= right && !ceilIndexFound; mid = (left + right) / 2) 
    {
        if (minElementForLength[mid] > key) 
            right = mid - 1;

        else if (minElementForLength[mid] == key) 
        {
            ceilIndex = mid;
            ceilIndexFound = true;
        }
        else if (mid + 1 <= right && minElementForLength[mid + 1] >= key) 
        {
            minElementForLength[mid + 1] = key;
            ceilIndex = mid + 1;
            ceilIndexFound = true;
        }
        else 
        {
            left = mid + 1;
        }
    }

    if (!ceilIndexFound) 
    {
        if (mid == left)
        {
            minElementForLength[mid] = key;
            ceilIndex = mid;
        }
        else 
        {
            minElementForLength[mid + 1] = key;
            ceilIndex = mid + 1;
        }
    }

    return ceilIndex+1; /*���� ��� +1, �� ���� �����-�� ��-� ������ ����������� �� ����������+1 */
}