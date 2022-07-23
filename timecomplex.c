#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//functions declarations
void swap(long int* a,long int* b);
void bubbleSort(long int arr[], long int n);
void insertionSort(long int arr[], long int n);
void merge(long int arr[], long int l, long int m, long int r);
void mergeSort(long int arr[], long int l, long int r);

int main(){
    clock_t start, end;
    double exe1[10], exe2[10], exe3[10];
    long int n = 10000;
    int i = 0;
    printf("A_Size, Bubble, Insertion, Merge\n");
    while(i < 10){
        long int a[n], b[n], c[n];
        for(int j = 0; j < n; j++){
            long int num = rand() % n + 1; // for average case
            //long int num = j; // for best case
            //long int num = n - j; // for worst case
            a[j] = num;
            b[j] = num;
            c[j] = num;
        }
        //Bubble sort
        start = clock();
        bubbleSort(a, n);
        end = clock();
        exe1[i] = ((double) end - start)/CLOCKS_PER_SEC;

        //InsertionSort
        start = clock();
        bubbleSort(b, n);
        end = clock();
        exe2[i] = ((double) end - start)/CLOCKS_PER_SEC;

        //MergeSort
        start = clock();
        mergeSort(c, 0, n-1);
        end = clock();
        exe3[i] = ((double) end - start)/CLOCKS_PER_SEC;

        printf("%li, %lf, %lf, %lf\n", n, exe1[i], exe2[i], exe3[i]);
        n += 10000;

    i++;
    }
    return 0;
}

void swap(long int* a,long int* b){
    long int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(long int arr[], long int n){
    for(long int i = 0; i < n - 1; i++){
        for(long int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j+1]) 
                swap(&arr[j], &arr[j+1]);
        }
    }
}

void insertionSort(long int arr[], long int n){
    long int i, key, j;
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

void merge(long int arr[], long int l, long int m, long int r)
{
	long int i, j, k;
	long int n1 = m - l + 1;
	long int n2 = r - m;

	long int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(long int arr[], long int l, long int r)
{
	if (l < r) {
		long int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

