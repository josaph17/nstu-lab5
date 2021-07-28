/*11. ���������� ��������.�� ������� ����� ������������ ��������� ���������� ������������������ ���������,
����������� � ������� �����������, ����������� � �������� ������ � ���������� �� ������� �� �-1�. �����
���������� �������� ���������� � ���������� ������������� ������������������ ������� ����������.*/
#include <stdio.h>
#include <locale.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 8

void ShowArray(int A[], int n);
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

int habrLength(int in[], int n) 
{
    /*���� ������� ������ ������������� �������� � �������, ��������� ������� � �����, 
    ����� ��������� ������� ������ ������������� � ���� �������*/
    if (n <= 1) 
        return 1;

    int lis_length = 1; /*���� -1 , �� ����������� ����� ������������������ 1 (�� ������< �.�. � ������ ��� ��-� ���� ������)*/

    int minElementForLength[N]; /*����� �� ������ ��� ������ ����� ��������������������� ����������� �������, �� ������� ��� ����� ������������*/
    int indexes[N]; /*������ � ������� �������� ����� �������������������, ������� ������������ �� ���� �������*/

    for (int i = 0; i < n; ++i) 
        minElementForLength[i] = INT_MAX; /*��������� ������ ������������������� ������������� ����������*/

    minElementForLength[0] = in[0];
    indexes[0] = 0; //���� 0, ����� ����������� ������ 1

    for (int i = 1; i < n; i++) /*�������� ������ ���� ���������������������*/
    {
        indexes[i] = ceilIndex(minElementForLength, 0, i, in[i]); /*��������� ����������� ������ indexes, ��������������� i*/

          if (lis_length < indexes[i]) {
            lis_length = indexes[i]; /*����� ����� ������� ��������������������� -1, ������������ ������� �������*/
        }
    }
    printf("������ indexes �����: \n");
    ShowArray(indexes, N);  
    printf("������  minElementForLength �����: \n");
    ShowArray(minElementForLength, N);

     return lis_length+1; /*+1 ����� ����� ������������ �����*/
}

int ceilIndex(int minElementForLength[], int startLeft, int startRight, int key)  //(.., 0, i, 5key = in[i])
/*�-� ������� ���������� ������������ ���-�� ��-�, ������ ���� ������ ����� ���� ������ �� �����������*/
{

    int mid = 0; /*�������� �������� �������� �������, �.�. �� ����� �������� � ������ �������*/
    int left = startLeft; /*������  ��-� ������� � �������� ���������� �������, ������ 0*/
    int right = startRight; /*������ �������� �� ������� ������������� �������*/
    int ceilIndex = 0; /*����� ��� ���� ����� ��������� �������� � ������ ���� �������������������*/
    bool ceilIndexFound = false; /*����*/
    ShowArray(minElementForLength, N);

    for (mid = (left + right) / 2; left <= right && !ceilIndexFound; mid = (left + right) / 2) 
    {
        if (minElementForLength[mid] > key) /*���� �������� �� �������  ������ �����*/
            right = mid - 1;

        else if (minElementForLength[mid] == key) 
        {
            ceilIndex = mid;
            ceilIndexFound = true;  /*�� �������� � 107*/
        }
        else if (mid + 1 <= right && minElementForLength[mid + 1] >= key) 
            /*��������������� ������� ���������-� (�) ������ ��� ���������� ������� � ������� (Nmax), �� ������ ��� ���� ���������*/
        {
            minElementForLength[mid + 1] = key; /*������ key � �����, �.�. ��� ����� �������� ������ ���������-� */
            ceilIndex = mid + 1; /*������� ������ ������� ����� ����� ������� -1*/
            ceilIndexFound = true; /*����� ����� �� ����� for, ��� true �� ������� �� �� ������*/
            /*�� �������� � 107*/
        }
        else /*����� �� ���� ���� ������ ��� ��������� ��-� ���������������������*/
        {
            left = mid + 1; /*7<8*/
        }
    }

    if (!ceilIndexFound)  /*���� ceilndex found = false, �� ��� �������������   !ceilIndexFound = true � ������ � ����*/
    {
        if (mid == left)
        {
            minElementForLength[mid] = key; /*����� ���� ����� ����� 1 ��-�*/
            ceilIndex = mid;
        }
        else 
        {
            minElementForLength[mid + 1] = key;
            ceilIndex = mid + 1; /*������ ������ ��-� �� ������� ������������ �������, 24 ������ �� 8*/
        }
    }

    return ceilIndex; /*���� ��� +1, �� ���� �����-�� ��-� ������ ����������� �� ����������+1 */
}