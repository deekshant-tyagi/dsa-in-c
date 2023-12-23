#include<stdio.h>
int main(){
    int a[100],i,n,pos;
    printf("Enter size of an Array: ");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("Enter No: ");
        scanf("%d",&a[i]);
    }
    printf("Enter position to delete: ");
    scanf("%d",&pos);
    for(i=pos-1; i<n-1; i++){
        a[i]=a[i+1];
    }
    printf("Array after Deletion is:\n");
    for(i=0; i<n-1; i++)
    printf("%d\n",a[i]);
    return 0;
}

/* IMP points to remember
1-> (i<n-1) remember to put i<n-1 in last for loop statement bcz after deletion size of array is decreased by one.
2-> you can use index var in place of pos for better understanding,bcz index starts from 0.
3-> for(i=pos-1; i<n-1; i++){
        a[i]=a[i+1]; // we are shifting elements to left.
    }
*/