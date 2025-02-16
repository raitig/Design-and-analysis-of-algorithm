// Write a program in c for sorted an array of n numbers of element using any algorithm having best case time complexity of O(n^2).
#include <stdio.h>
void selection_sort(int a[], int size)
{
    int i, j, min, temp;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != 1)
        {
            temp = a[min];
            a[min] = a[i],a[i] = temp;
        }
    }
    
}
int main(){
    int i,n,j;
    printf("Enter the number of element :");
    scanf("%d",&n);
    int arr[n];
    printf("|n Enter %d element for array :",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selection_sort(arr,n);
    printf("\n the sorted array :");
    for(i=0;i<n;i++){
        printf("[%d]",arr[i]);
    }
    return 0;
}
