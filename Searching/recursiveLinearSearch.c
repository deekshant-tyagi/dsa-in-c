#include <stdio.h>
int recursiveLinearSearch(int a[], int index, int n, int number)
{
    int pos;
    while (index <= n)
    {
        if (a[index] == number)
        {
            pos = index + 1;
            return pos;
        }
        else
        {
            return recursiveLinearSearch(a, index + 1, n, number);
        }
    }

    return -1;
}

int main()
{
    int a[100], n, i, found, pos, number;
    printf("Enter size of an array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter No: ");
        scanf("%d", &a[i]);
    }
    printf("Enter number to Search: ");
    scanf("%d", &number);
    found = recursiveLinearSearch(a, 0, n - 1, number);
    if (found == -1)
    {
        printf("Element Not found");
    }
    else
    {
        printf("Element found at position: %d", found);
    }
    return 0;
}