#include <stdio.h>
int main()
{
    int a[100], n, i, j, temp;
    printf("Enter size of an array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter No: ");
        scanf("%d", &a[i]);
    }
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    printf("Array after sorting is:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0;
}