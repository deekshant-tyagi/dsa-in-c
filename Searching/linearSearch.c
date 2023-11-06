// Linear Search in C.
#include<stdio.h>
int main() {
    int a[100],n,i,pos,number,flag=0;
    printf("Enter size of an array: ");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("Enter No: ");
        scanf("%d",&a[i]);
    }
    printf("Enter no you want to Search: ");
    scanf("%d",&number);
    for(i=0; i<n; i++){
        if(a[i]==number){
            pos=i+1;
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("No found at %d position",pos);
    }
    else{
        printf("No not found.");
    }
    return 0;
}