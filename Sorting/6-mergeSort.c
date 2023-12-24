#include <stdio.h>
void mergeSort();
void merge();
int main()
{
    int a[100], n, i;
    printf("Enter size of an array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter No: ");
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0, n - 1);
    printf("Array after sorting is:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0;
}

void mergeSort(int a[100], int first, int last)
{
    int mid;
    if (first < last)
    {
        mid = (first + last) / 2;
        mergeSort(a, first, mid);
        mergeSort(a, mid + 1, last);
        merge(a, first, mid, last);
    }
}

void merge(int a[100], int first, int mid, int last)
{
    int b[100];
    int i, j, k;
    i = first;
    k = first;
    j = mid + 1;
    while (i <= mid && j <= last)
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    if (i > mid)
    {
        while (j <= last)
        {
            b[k++] = a[j++];
        }
    }

    else
        {
            while (i <= mid)
            {
                b[k++] = a[i++];
            }
        }
    for (i = first; i <= last; i++)
        a[i] = b[i];
}