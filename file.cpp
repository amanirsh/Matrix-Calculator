
//including libraries
#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string>
#include <ctype.h>

#include "imp.h"  // header file which includes the implementation of all functions

using namespace std;


int main(){


	//some local declarations
	
	int array1[10][10], array2[10][10], array3[10][10];
	int i = 0; int j = 0;
	int m = 0; int n = 0;
	int  c1 = 0;
	int row1 = 0; int col1 = 0;
	int row2 = 0; int col2 = 0;
	int row3 = 0; int col3 = 0;
	int flag = 0, flag2 = 0;
	int count = 0;
	char c;

	ifstream is("readfile.txt");     // opening a file which contaions our matrices
	while (is.get(c))                //reading file char by char and saving matrices in 2D array
	{
	
		if (c == ']' && flag == 0 )       // if this sign comes then, it will know that we are done with the first matrix
		{
			flag = 1; row1 = i; col1 = j-1; 
			i = 0;  j = 0; 
		}

		if (flag == 0){
			if (c == '\n') { i++; j = 0; }

			if (isdigit(c)) // if character is a digit then save it in 2d array
			{

				array1[i][j] = int(c - '0'); // parsing the char into int, so that we can apply arithmetic operations on it
				j++;  // iterating the column

			}
		}
		if (flag != 0) {
			if (c == '['){
				i = 0; j = 0;
			}

			if (c == '\n') { i++; j = 0; }
			if (isdigit(c)){
				array2[i][j] = int(c - '0');
				
				j++;
					}
				}
		if (c == ']'){
			row2 = i;
			col2 = j - 1;
			count++;
			

			
		}
		if (count == 2){
			break;
		}

			}
	       
	        cout << "RUNNING FIRST TEST i.e multiplying two matrices\n";
			int d;
			cout << "\n";
			
			cout << "First Matrix \n";
			for (int r = 0; r <= row1; r++)
			{
			for (int l = 0; l <= col1; l++)
			{
			cout << array1[r][l] << "\t";

			}
			cout << "\n";
			}
			cout << "\n";

			cout << "Second Matrix  \n";
			
			for (int r = 0; r <=  row2; r++)
			{
				for (int l = 0; l <= col2; l++)
			{
			cout << array2[r][l] << "\t";

			}
				cout << "\n";
			}

			int raiseflag = 0;
			m = 0;
			cout << "\n";
			MatrixMultiply(array1, array2, row1, col1, row2, col2);
			cout << "\nRUNNING SECOND TEST i.e adding three matrices\n";
			sumofmatrix(array1, array2,row1,col1,row2,col2);
			for (int i = 0; i <= row1; i++)
			{
				for (int j = 0; j <= col1; j++){
					if (sum[i][j] != 0)
					{
						raiseflag = 1;
					}

				}
			}
			
			while (is.get(c))          
			{
				if (c == '['){
					flag = 1; i = 0; j = 0;
				}
				if (flag == 1){
					if (c == '\n') { i++; j = 0; }

					if (isdigit(c)) 
					{

						array3[i][j] = int(c - '0'); 
						j++;  

					}
				}
				if (c == ']'){
					row3 = i; col3 = j - 1;
				}

			}

			cout << "Third Matrix \n";
			for (int r = 0; r <= row3; r++)
			{
				for (int l = 0; l <= col3; l++)
				{
					cout << array3[r][l] << "\t";

				}
				cout << "\n";
			}
			if (raiseflag == 1) // call this function if the sum of the previous matrices is valid
			{
				sumofmatrix(array3, sum, row3, col3, row1, col1);
				//emptying the 2D array after operation
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j <10; j++){
						sum[i][j] = 0;

					}
				}
			}
			cout << "\nRUNNING THIRD TEST i.e multiplying two matrices and adding in third\n";
			sumofmatrix(matrixC, array3, row1, col2, row3, col3); // we have the result of two already multiplied matrices, I am adding the third in them
			
			getchar();
			getchar();
			is.close();                // close file
			return 0;	

	} //end of main
