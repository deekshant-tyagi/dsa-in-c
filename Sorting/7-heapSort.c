// Implementation of Heap Sort in C

#include <stdio.h>
void heapSort();
void heapify();
int main()
{
    int a[100], n, i;
    printf("Enter size of an Array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter No: ");
        scanf("%d", &a[i]);
    }
    heapSort(a, n);
    printf("Array after sorting is:\n");
    for(i=0; i<n; i++)
    printf("%d\n",a[i]);
    return 0;
}

void heapSort(int a[100], int n)
{
    // Build max heap
    int i,temp;
    for (i = n / 2; i >= 0; i--)
        heapify(a, i, n);

    for (i = n - 1; i >= 0; i--)
    {
        //   swap(&a[0], &a[i]);
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, 0, i);
    }
}

void heapify(int a[100], int i, int n)
{
    // Finding the max among root, left child, and right child of the tree
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;
    if (left < n && a[left] > a[max])
        max = left;

    if (right < n && a[right] > a[max])
        max = right;

    // Swap and continue heapifying if the root is not the max
    if (max != i)
    {
        //   swap(&a[i], &a[max]);
        temp = a[i];
        a[i] = a[max];
        a[max] = temp;
        heapify(a, max, n);
    }
}
