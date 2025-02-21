// Write a program in c for sorting an array of n numbers of element using the following algorithm .
// 1. Merge sort. 
// Write a program in c for sorting an array of n numbers of element using the following algorithm .
// 1. Merge sort.
#include<stdio.h>
void merge(int a[], int l, int mid, int h){
	int i,j,k;
	int size_1=mid-l+1;
	int size_2=h-mid;
	int L[size_1], R[size_2];
	for(i=0;i<size_1;i++){
		L[i]=a[l+i];
	}
	for(j=0;j<size_2;j++){
		R[j]=a[mid+1+j];
	}
	i=0;
	j=0;
	k=l;
	while(i<size_1 && j<size_2){
		if(L[i]<=R[j]){
			a[k]=L[i];
			i++;
	}
	else{
		a[k]=R[j];
		j++;
	}
	k++;
		
	}
	while(i<size_1){
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<size_2){
		a[k]=R[j];
		j++;
		k++;
	}
	
}  
void merge_sort(int a[], int l, int h){
	if(l<h){
		int mid=(l+h)/2;
		merge_sort(a,l,mid);
		merge_sort(a,mid+1,h);
		merge(a,l,mid,h);
		
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
	merge_sort(a,0,size-1);
	printf("\n Sorted array \n");
	for(i=0;i<size;i++){
		printf("[%d]",a[i]);
	}
	return 0;
}