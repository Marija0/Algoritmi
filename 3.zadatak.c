#include <stdio.h>
#include <stdlib.h>

/*kopirano s neta*/
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}
/*-----------*/


int Nadji_s(int A[], int p, int n) {
	int counter = 1;
	for (int i = 0; i < n; i++) {
		if (A[p] < A[i]) {
			counter++;
		}
	}
	return counter;
}

void ispisInt(int V[], int n) {
	//formatiranje ispisa
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d", V[i]);
		if (i != n - 1) {
			printf(", ");
		}
	}
	printf("\nIspisano je: %d elemenata.\n", n);
}

void kopiraj(int A[], int n, int* B) {

    for (int i = 0; i < n; i++) {
        B[i] = A[i];
    }
}

int main()
{
    int V[] =  {11, 15, 8, 7, 14, 17, 7, 8, 20, 6, 14, 7, 16};
    int *V_;
    const int N = (int)sizeof(V) / sizeof(int);		//velicina definiranog polja
    V_ = (int*)malloc(sizeof(int) * N);
    kopiraj(V, N, V_);
    int x = Nadji_s(V, 0, N);
    
    ispisInt(V, N);
	printf("\nElement ce zavrsiti na %d mjestu", x);

    quickSort(V_, 0, N-1);
    ispisInt(V, N);
    ispisInt(V_, N);

}
