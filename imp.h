
//including libraries
#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string>
#include <ctype.h>

using namespace std;

int sum[10][10];      // result of sum
int matrixC[10][10];  // result of multiplication  

// this function add two matrices if their order are same and stores the result in a global 2D array
void sumofmatrix(int first[10][10], int second[10][10], int row1, int col1, int row2, int col2){
	int count1 = 0;
	int count2 = 0;
	int j = 0;
	int  c1 = 0;
	int d = 0;
	if ((row1 == row2) && (col1 == col2)){
		for (c1 = 0; c1 <= row1; c1++){
			for (d = 0; d <= col1; d++){

				sum[c1][d] = first[c1][d] + second[c1][d];

			}
		}

		cout << "Sum of entered matrices:-\n";

		for (c1 = 0; c1 <= row1; c1++)
		{
			for (d = 0; d <= col1; d++)
				cout << sum[c1][d] << "\t";

			cout << endl;
		}


	}
	else {
		cout << "addition is not possible because matrix are not of the same order\n";
	}

}

//This function subtracts two matrices if their order are same
void Subofmatrix(int first[10][10], int second[10][10], int row1, int col1, int row2, int col2){
	int  c1 = 0;
	int d = 0;
	int sub[2][2];
	if ((row1 == row2) && (col1 == col2)){
		for (c1 = 0; c1 < 2; c1++){
			for (d = 0; d < 2; d++){

				sub[c1][d] = first[c1][d] - second[c1][d];

			}
		}

		cout << "Sum of entered matrices:-\n";

		for (c1 = 0; c1 < 2; c1++)
		{
			for (d = 0; d < 2; d++)
				cout << sub[c1][d] << "\t";

			cout << endl;
		}

	}
	else {
		cout << "addition is not possible because matrices are not of the same order\n";
	}
}

//this function multiply two matrcies if column of first matrix is equal to rows of the second matrix and stores the result in global 2D array
void MatrixMultiply(int first[10][10], int second[10][10], int row1, int col1, int row2, int col2)
{

	if (col1 == row2){
		for (int i = 0; i <= row1; i++){
			for (int j = 0; j <= col2; j++){
				matrixC[i][j] = 0;
				for (int k = 0; k <= col1; k++){
					matrixC[i][j] = matrixC[i][j] + (first[i][k] * second[k][j]);
				}
			}
		}
		cout << "result of matrix multiplication\n";
		for (int i = 0; i <= row1; i++){
			for (int j = 0; j <= col2; j++){
				cout << matrixC[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else
		cout << "Matrix Multiplication is not possible\n";
}