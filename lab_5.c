/*11. Сортировка “хитрая”.Из массива путем однократного просмотра выбирается последовательность элементов,
находящихся в порядке возрастания, переносятся в выходной массив и заменяются во входном на “-1”. Затем
оставшиеся элементы включаются в полученную упорядоченную последовательность методом погружения.*/
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
    printf("Длина максимально длинной послед-и: %d\n", length);	
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
    /*Если элемент больше максимального элемента в массиве, добавляем элемент в конец, 
    когда следующий элемент меньше максимального в этом массиве*/
    if (n <= 1) 
        return 1;

    int lis_length = 1; /*было -1 , но минимальная длина полседовательности 1 (не строки< т.к. в строке все эл-ы идут подряд)*/

    int minElementForLength[N]; /*здесь мы храним для каждой длины подпоследовательности минимальный элемент, на которым она может оканчиваться*/
    int indexes[N]; /*массив в котором хранятся длины последовательностей, которые оканчиваются на этот элемент*/

    for (int i = 0; i < n; ++i) 
        minElementForLength[i] = INT_MAX; /*заполняем массив последовательностей маскимальными элеиентами*/

    minElementForLength[0] = in[0];
    indexes[0] = 0; //было 0, длина минимальной послед 1

    for (int i = 1; i < n; i++) /*заполяем массив длин послендовательнностей*/
    {
        indexes[i] = ceilIndex(minElementForLength, 0, i, in[i]); /*заполняем параллельно массив indexes, соответственено i*/

          if (lis_length < indexes[i]) {
            lis_length = indexes[i]; /*длина самой длинной подпоследовательности -1, впоследствии значеие индекса*/
        }
    }
    printf("Массив indexes равен: \n");
    ShowArray(indexes, N);  
    printf("Массив  minElementForLength равен: \n");
    ShowArray(minElementForLength, N);

     return lis_length+1; /*+1 чтобы найти максимальную длину*/
}

int ceilIndex(int minElementForLength[], int startLeft, int startRight, int key)  //(.., 0, i, 5key = in[i])
/*ф-я которая возвращает максимальное кол-во эл-в, котрые могу стоять перед этим числом по возрастанию*/
{

    int mid = 0; /*обнуляем значение середины отрезка, т.к. мы будем работать с новыми данными*/
    int left = startLeft; /*индекс  эл-а массива с которого начинается отрезок, всегда 0*/
    int right = startRight; /*индекс элемента на котором заканчивается отрезок*/
    int ceilIndex = 0; /*нужен для того чтобы присвоить значение в массив длин последовательностей*/
    bool ceilIndexFound = false; /*флаг*/
    ShowArray(minElementForLength, N);

    for (mid = (left + right) / 2; left <= right && !ceilIndexFound; mid = (left + right) / 2) 
    {
        if (minElementForLength[mid] > key) /*если предпосл эл массива  больше ключа*/
            right = mid - 1;

        else if (minElementForLength[mid] == key) 
        {
            ceilIndex = mid;
            ceilIndexFound = true;  /*не попадаем в 107*/
        }
        else if (mid + 1 <= right && minElementForLength[mid + 1] >= key) 
            /*рассматриваемые элемент подпослед-и (х) меньше чем наибольший элемент в массиве (Nmax), но больше чем посл подстроки*/
        {
            minElementForLength[mid + 1] = key; /*ставим key в конец, т.е. это число заменяем концом подпослед-и */
            ceilIndex = mid + 1; /*придаем индекс который равен длине подпосл -1*/
            ceilIndexFound = true; /*чтобы выйти из цикла for, при true из массива мы не выйдем*/
            /*не попадаем в 107*/
        }
        else /*вроде бы если ключ больше чем последний эл-т подпоследовательности*/
        {
            left = mid + 1; /*7<8*/
        }
    }

    if (!ceilIndexFound)  /*если ceilndex found = false, то при инверитовании   !ceilIndexFound = true и входим в тело*/
    {
        if (mid == left)
        {
            minElementForLength[mid] = key; /*когда ключ имеет длину 1 эл-т*/
            ceilIndex = mid;
        }
        else 
        {
            minElementForLength[mid + 1] = key;
            ceilIndex = mid + 1; /*замена послед эл-а на который оканчивается подпосл, 24 меняем на 8*/
        }
    }

    return ceilIndex; /*было без +1, но если какой-то эл-т больше предыдущего то прибавляем+1 */
}