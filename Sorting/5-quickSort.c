#include <stdio.h>
void quickSort();
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
    quickSort(a, 0, n - 1);
    printf("Array after sorting is:\n");
    for (i = 0; i < n; i++)
    printf("%d\n", a[i]);
    return 0;
}

void quickSort(int a[100], int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (a[i] <= a[pivot])
                i++;
            while (a[j] > a[pivot])
                j--;
            if (i < j)
            {
                temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        // when i & j cross each other.
        // then we swap a[j] & pivot.
        temp = a[pivot];
        a[pivot]=a[j];
        a[j]=temp;
        quickSort(a,0,j-1);
        quickSort(a,j+1,last);
    }
}