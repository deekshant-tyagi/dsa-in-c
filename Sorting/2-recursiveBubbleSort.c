#include<stdio.h>
void recursiveBubbleSort(int a[], int n){
    int temp;
    int j;
        for (j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
   if (n - 1 > 1) {
    recursiveBubbleSort(a,n-1);
    }
}


int main(){
    int a[100],n,i;
    printf("Enter size of an array: ");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("Enter No: ");
        scanf("%d",&a[i]);
    }
    recursiveBubbleSort(a,n);
    printf("Array after sorting is:\n");
    for(i=0; i<n; i++)
    printf("%d\n",a[i]);
    return 0;
}