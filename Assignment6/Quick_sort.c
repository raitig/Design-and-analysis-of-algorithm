// Write a program in c for sorting an array of n numbers of element using the following algorithm .
// Quick sort.
#include<stdio.h>
int partition(int a[], int l, int h){
int pivot =a[l];
int start =l;
int end =h;
int temp_1, temp_2;
while(start<end){
	while(a[start]<=pivot){
		start++;
	}
	while(a[end]>pivot){
		end --;
	}
	if(start<end){
		temp_1=a[start];
		a[start]=a[end];
		a[end]=temp_1;
	}
}
	temp_2=a[l];
	a[l]=a[end];
	a[end]=temp_2;
	return end;
	}
	void quick_sort(int a[], int l, int h){
		int loc;
		if(l<h){
			loc=partition(a,l,h);
			quick_sort(a,l,loc-1);
			quick_sort(a,loc+1,h);
		}
	}
int main(){
	int size,i;
	printf("Enter the size of array :");
	scanf("%d",&size);
	int a[size];
	printf("\n Enter the Elements of the array :");
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	printf("\n The elements of the array \n");
	for(i=0;i<size;i++){
		printf("[%d]",a[i]);
	}
	quick_sort(a,0,size-1);
	printf("\n Sorted array \n");
	for(i=0;i<size;i++){
		printf("[%d]",a[i]);
	}
	return 0;
}
