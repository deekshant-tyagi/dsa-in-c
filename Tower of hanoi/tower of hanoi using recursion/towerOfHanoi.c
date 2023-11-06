// Tower of hanoi using recursion
#include<stdio.h>
void tower(int n, char beg, char mid, char end){
    if(n<=0){
        printf("Invalid Input !");
    }
    else if(n==1){
        printf("\nMove disc from %c to %c", beg, end);
    }
    else{
        tower(n-1,beg,end,mid);
        tower(1,beg,mid,end);
        tower(n-1,mid,beg,end);
    }
}
int main(){
    int n;
    char a,b,c;
    printf("Enter no of disc: ");
    scanf("%d",&n);
    printf("Tower of hanoi of %d disc: ",n);
    tower(n,'a','b','c');
    return 0;
}