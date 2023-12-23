#include<stdio.h> 
int recursiveBinarySearch(int a[], int start, int end, int number){
    int mid;
    while(start<=end){
        mid=(start+end)/2;
        if(a[mid]==number)
        return mid;
        if(a[mid]>number){
            return recursiveBinarySearch(a,start,mid-1,number);
        }
        else{
            return recursiveBinarySearch(a,mid+1,end,number);
        }
    }
    return -1;
}
int main(){
    int a[100],n,i,found,number;
    printf("Enter size of an array: ");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("Enter No: ");
        scanf("%d",&a[i]);
    }
    printf("Enter no to search: ");
    scanf("%d",&number);
    found = recursiveBinarySearch(a,0,n-1,number);
    if(found==-1){
        printf("Element not found");
    }
    else{
        printf("Element found at index: %d",found);
    }
    return 0;
}