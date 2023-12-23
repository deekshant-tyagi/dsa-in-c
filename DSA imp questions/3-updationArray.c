#include<stdio.h>
int main(){
    int a[100],i,n,pos,val;
    printf("Enter size of an array: ");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("Enter No: ");
        scanf("%d",&a[i]);
    }
    printf("Enter position to update: ");
    scanf("%d",&pos);
    printf("Enter value to update: ");
    scanf("%d",&val);
    for(i=0; i<n; i++){
        if(i==pos-1){
            a[i]=val;
        }
    }
    printf("Array after updation is :\n");
    for(i=0; i<n; i++)
    printf("%d\n",a[i]);
    return 0;
}