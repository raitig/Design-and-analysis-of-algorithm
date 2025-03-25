// Write a program in C to implement the strassen's Algorithm for matrix multiplication .
#include<stdio.h>
#include<stdlib.h>
int ispowerofTwo(int x){
	return (x != 0) && ((x &(x - 1)) == 0);
}
void printMatrix(int n, int** arr){
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%2d ",arr[i][j]);
		}
		printf("\n");
	}
}
void splitMatrix(int** source, int** Dest, int p, int q, int n){
	for (int i1 = 0, i2 = p; i1 < n; i1++,i2++){
		for(int j1 = 0, j2 = q; j1 < n; j1++,j2++){
			Dest[i1][j1] = source[i2][j2];
		}
	}
}
void JoinMatrix(int** Child, int** parent, int p, int q, int n){
	for (int i1 = 0, i2 = p; i1 < n; i1++,i2++){
		for(int j1 = 0, j2 = q; j1 < n; j1++,j2++){
			parent[i2][j2] = Child[i1][j1];
		}
	}
}
int** createMatrix(int Rows, int cols){
	int **matrix = (int **)malloc(Rows * sizeof(int *));
	int row;
	for (row = 0; row < Rows; row++){
		matrix[row] = (int *)malloc(cols * sizeof(int));
	}
	return matrix;
}
int** mAdd(int n, int** A, int** B){
	int** sum = createMatrix(n,n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			sum[i][j] = A[i][j] + B[i][j];
		} 
	}
	return sum;
}

int** msub(int n, int** A, int** B){
	int** diff = createMatrix(n,n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			diff[i][j] = A[i][j] - B[i][j];
		} 
	}
	return diff;
}
int** strassenMatMul(int n, int **M1, int **M2){
	int** result = createMatrix(n,n);
	if(n==1){
		result[0][0] = M1[0][0] * M2[0][0];
	}else{
		int m = n/2;
		int** M1A = createMatrix(m,m);
		splitMatrix(M1,M1A,0,0,m);
		int** M1B = createMatrix(m,m);
		splitMatrix(M1,M1B,0,m,m);
		int** M1C = createMatrix(m,m);
		splitMatrix(M1,M1C,m,0,m);
		int** M1D = createMatrix(m,m);
		splitMatrix(M1,M1D,m,m,m);
		
		int** M2A = createMatrix(m,m);
		splitMatrix(M2,M2A,0,0,m);
		int** M2B = createMatrix(m,m);
		splitMatrix(M2,M2B,0,m,m);
		int** M2C = createMatrix(m,m);
		splitMatrix(M2,M2C,m,0,m);
		int** M2D = createMatrix(m,m);
		splitMatrix(M2,M2D,m,m,m);
		
		int** Mat1 = strassenMatMul(m,mAdd(m,M1A, M1D), mAdd(m,M2A, M2D));
		int** Mat2 = strassenMatMul(m,mAdd(m,M1C, M1D),M2A);
		int** Mat3 = strassenMatMul(m,M1A, msub(m,M2B, M2D));
		int** Mat4 = strassenMatMul(m,M1D, msub(m,M2C, M2A));
		int** Mat5 = strassenMatMul(m,mAdd(m,M1A, M1B), M2D);
		int** Mat6 = strassenMatMul(m,msub(m,M1C, M1A), mAdd(m,M2A, M2B));
		int** Mat7 = strassenMatMul(m,msub(m,M1B, M1D), mAdd(m,M2C, M2D));
		
		int** C11 = mAdd(m,msub(m,mAdd(m,Mat1, Mat4), Mat5), Mat7);
		int** C12 = mAdd(m,Mat3, Mat5);
		int** C21 = mAdd(m,Mat2, Mat4);
		int** C22 = mAdd(m,msub(m,mAdd(m,Mat1, Mat3), Mat2), Mat6);
		
		JoinMatrix(C11, result, 0, 0,m);
		JoinMatrix(C12, result, 0, m,m);
		JoinMatrix(C21, result, m, 0,m);
		JoinMatrix(C22, result, m, m,m);
	}
	return result;
}
int main(){
	int n; 
	printf("Enter the dimension (must be a power of 2):");
	scanf("%d",&n);
	if(ispowerofTwo(n)){
		int** arr = createMatrix(n,n);
		int** brr = createMatrix(n,n);
			printf("Enter the element of the first matrix :");
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				scanf("%d", &arr[i][j]);
			}
		}
		printf("Matrix A:\n");
		printMatrix(n,arr);
			printf("Enter the element of the second matrix :");
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				scanf("%d", &brr[i][j]);
			}
		}
		printf("Matrix B:\n");
		printMatrix(n,brr);
		printf("Result of M1 x M2 : \n");
		int** crr = strassenMatMul(n,arr,brr);
		printMatrix(n,crr);
	}else{
		printf("Dimension Not a power of 2!");
	}
	return 0;
}
