#include<stdio.h>
#include<stdlib.h>


void troca(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int divide(int array[], int p, int r)
{
	int pivot = array[r];
	int i = (p - 1);

	for (int j = p; j <= r- 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			troca(&array[i], &array[j]);
		}
	}
	troca(&array[i + 1], &array[r]);
	return (i + 1);
}


void quickSort(int array[], int p, int q)
{
	if (p < q)
	{
		int pi = divide(array, p, q);
		quickSort(array, p, pi - 1);
		quickSort(array, pi + 1, q);
	}
}

void imprimir(int array[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", array[i]);
}

int main()
{
	int array[] = {10, 7, 8, 9, 1, 5};
	int size = sizeof(array)/sizeof(array[0]);
	quickSort(array, 0, size-1);
	imprimir(array, size);
	return 0;
}

