#include <stdio.h>
void radixSort();
void countSort();
int getMax();

// main function
int main()
{
    //  user input for the array
    int a[100], n, i;
    printf("Enter size of an array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter No: ");
        scanf("%d", &a[i]);
    }

    // calling radixSort
    radixSort(a, n);

    // printing sorted array
    printf("Sorted Array is:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0;
}

// radixSort algorithm
void radixSort(int a[], int n)
{
    int m, pos;
    m = getMax(a, n);

    // call countSort algorithm for each digit
    for (pos = 1; m / pos > 0; pos *= 10)
        countSort(a, n, pos);
}

// to get the element with maximum value
int getMax(int a[], int n)
{
    int max, i;
    max = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

// Count Sort algorithm
void countSort(int a[], int n, int pos)
{
    int b[n];             // to store a sorted array
    int i, cnt[10] = {0}; // to keep count of values

    // count number of values
    for (i = 0; i < n; i++)
        cnt[(a[i] / pos) % 10]++;

    // count index for each
    for (i = 1; i < 10; i++)
        cnt[i] += cnt[i - 1];

    // place the elements at a particular index to sort the array
    for (i = n - 1; i >= 0; i--)
    {
        b[cnt[(a[i] / pos) % 10] - 1] = a[i];
        cnt[(a[i] / pos) % 10]--;
    }

    // copy b in a
    for (i = 0; i < n; i++)
        a[i] = b[i];
}