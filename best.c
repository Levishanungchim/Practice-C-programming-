#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void mergesort(long int a[], long int n);
void merge(long int a[], long int l[], long int r[], long int leftcount, long int rightcount);

double mergeTime(long int arr[],long int n)
{
    clock_t start, end;
    double execution_time;
    start = clock();
    int i;
    for (i = 0; i < n; i++)
        arr[i] = i;
    mergesort(arr, n);
    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    return duration;
}
void mergesort(long int a[], long int n)
{
    long int mid, i, *l, *r;
    if (n < 2)
        return;
    mid = n / 2;
    l = (long int *)malloc(mid * sizeof(long int));
    r = (long int *)malloc((n - mid) * sizeof(long int));
    for (i = 0; i < mid; i++)
        l[i] = a[i];
    for (i = mid; i < n; i++)
        r[i - mid] = a[i];
    mergesort(l, mid);
    mergesort(r, n - mid);
    merge(a, l, r, mid, n - mid);
    free(l);
    free(r);
}ftcount, long int rightcount)
{
    long int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    while (i < leftcount && j < rightcount)
    {
        if (l[i] < r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
        k++;
    }
    while (i < leftcount)
    {
        a[k] = l[i];
        i++;
        k++;
    }
    while (j < rightcount)
    {
        a[k] = r[j];
        j++;
        k++;
    }
}
void swap(long int* a, long int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
double bubbleTime(long int arr[],long int n)
{
    clock_t start, end;
    start = clock();   
    long int i, j;
    for (i = 1; i <= n - 1; i++)
    {
        for (j = 0; j < (n - i); j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j+1]);
        }
    }
    end = clock(); 
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    return duration;
}
double insertionTime(long int arr[], long int n)
{
    clock_t start, end;
    start = clock();   
    long int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;


        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    end = clock(); 
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    return duration;
}
void main()
{
    long int i, n;
    double t1, t2, t3;
    long int arr[100000];
    printf("SIZE(n)\t\t Bubble exe time\t Insertion exe time\t Merge exe time\n");
    for(n=10000; n<=100000; n+=10000)
    {
        for(i=0; i<n; i++)
            arr[i]=i;
        t1 = bubbleTime(arr, n);
        t2 = insertionTime(arr, n);
        t3 = mergeTime(arr, n);
        printf("%li\t\t %.3lf\t\t\t %.3lf\t\t\t %.3lf\t\t\t\n",n, t1, t2, t3);
    }
}