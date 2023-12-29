#include<stdio.h>
#include<stdlib.h>
void indexSequentialSearch();
void seqSearch();

int main(){
    int arr[100],n,key,i;
    printf("Enter size of an array:  ");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d",&key);

    indexSequentialSearch(arr,n,key);
    return 0;
}

void indexSequentialSearch(int arr[], int n, int key)
{
    int index[20], i;
    int x=0,start,end,bs;
    printf("Enter block size: ");
    scanf("%d",&bs);

    for(i=0; i<n; i=i+bs)
    index[x++]=i;

    if(key<arr[index[0]] || key>arr[index[x-1]]){
        printf("Element not found");
        exit(0);
    }
    else{
        for(i=1; i<=x; i++)
        if(key<=arr[index[i]]){
            start = index[i-1];
            end = start+bs;
            break;
        }
    }
    seqSearch(arr,start,end,key);
}

void seqSearch(int arr[], int start, int end, int key)
{
    int i, flag=0,pos;
    for(i=start; i<=end; i++)
    {
        if(key==arr[i])
        {
            pos=i+1;
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("key is found at %d",pos);
    }
    else{
        printf("Element not found");
    }
}
