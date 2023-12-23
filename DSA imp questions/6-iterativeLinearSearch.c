#include<stdio.h>
int main(){
    int a[100],n,i,number,pos,flag=0;
    printf("Enter size of an array: ");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("Enter No: ");
        scanf("%d",&a[i]);
    }
    printf("Enter element to search: ");
    scanf("%d",&number);
    for(i=0; i<n; i++){
        if(a[i]==number){
            pos=i+1;
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("Element Not Found");
    }
    else{
        printf("Element found at position: %d",pos);
    }
    return 0;
}