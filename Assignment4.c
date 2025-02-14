#include<stdio.h>
int recursivefactorial(int n){
	return ((n==0)||(n==1))?1:n*recursivefactorial(n-1);
}
int recursivesumdigits(int n){
	return (n==0)?0:((n%10)+recursivesumdigits(n/10));
}
int recursivebinaryconvert(int n){
	return ((n==0)||(n==1))?n:((n%2)+10*recursivebinaryconvert(n/2));
}+
int main(){
	int choice,n;
	do{
		printf("Enter your choice :\n1.Calculate the factorial of a given number.\n2.Calculate the sum of digits of a number.\n3.Convert a given deciaml numbers to binary.\nchoice");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the number :");
			scanf("%d",&n);
			printf("The factorial of %d is: %d \n",n,recursivefactorial(n));
			break;
			case 2:
			printf("Enter the number :");
			scanf("%d",&n);
			printf("The sum of digit of %d is: %d \n",n,recursivesumdigits(n));
			break;
			case 3:
				printf("Enter the number:");
				scanf("%d",&n);
				printf("The binary form of %d is: %d\n",n,recursivebinaryconvert(n));
				break;
				case-1:
					break;
					default:
						printf("Wrong choice!\n");
						break;
		}
	}while(choice!=-1);
	return 0;
}
