// Binary search using interative approach
#include <stdio.h>
int iterativeBinarySearch(int a[], int start, int end, int number){
   int mid;
   while (start <= end){
      mid = (start + end)/2;
      if (a[mid] == number)
         return mid;
      if (a[mid] < number)
         start = mid + 1;
      else
         end = mid - 1;
   }
   return -1;
}
int main(){
   int a[100],n,i,number,found;
   printf("Enter size of array: ");
   scanf("%d",&n);
   for(i=0; i<n; i++){
      printf("Enter no: ");
      scanf("%d",&a[i]);
   }
   printf("Enter no u want to search: ");
   scanf("%d",&number);
   found = iterativeBinarySearch(a, 0, n-1, number);
   if(found == -1 ) {
      printf("Element not found in the array ");
   }
   else {
      printf("Element found at index : %d",found);
   }
   return 0;
}