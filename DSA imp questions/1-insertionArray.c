#include<stdio.h>
int main(){
    int a[100],i,n,pos,val;
    printf("Enter size of an Array: ");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("Enter No : ");
        scanf("%d",&a[i]);
    }
    printf("Enter position to Insert an Element: ");
    scanf("%d",&pos);
    printf("Enter value to Insert: ");
    scanf("%d",&val);
    for(i=n-1; i>=pos-1; i--){
        a[i+1]=a[i];
    }
    a[pos-1]=val;
    printf("Array after insertion is :\n");
    for(i=0; i<=n; i++)
    printf("%d\n",a[i]);
    return 0;
}

/* IMP points to remember
1. (i<=n) Make sure to put i<=n in last for loop statement because after insertion the size of an array is increased by one. So we have to traverse the array until i<n+1 or i<=n.
 2-> logic (n-1) because index starts from 0, (pos-1) as we know index starts form 0 it means pos 4 is at index 3 similarly so on.
     for(i=n-1; i>=pos-1; i--){
        a[i+1]=a[i]; // we are shifting elements to right.
    }
    a[pos-1]=val; // if we want to insert at position 4 and pos 4 can be picked by index of array. pos 4 -> a[3]=val;

    3->
      if (pos >= n+1)  
    {  
        printf (" \n Insertion is not possible in the array.");  
    }
    we can add this condition to check if the position given by user is correct or not.
*/
