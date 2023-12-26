/*

Author : Partha Biswas
Date : 25/12/2023
Problem : Determinant of a Matrix
Problem Link : https://www.geeksforgeeks.org/problems/determinant-of-a-matrix-1587115620/1
*/

//{ Driver Code Starts
//Initial Template for C

#include <stdio.h>


// } Driver Code Ends
//User function Template for C


//Function for finding determinant of matrix.
int determinantOfMatrix(int n, int matrix[][n]);

// Recursive function to find the determinant of a matrix
int determinantOfMatrixHelper(int n, int matrix[][n]) {
    if (n == 1)
        return matrix[0][0];

    int ans = 0;

    // Traverse all columns of the 0th row
    for (int i = 0; i < n; i++) {
        int second[n - 1][n - 1];
        int x = 0, y = 0;

        // Traverse all rows and columns of the second matrix
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (k != i) {
                    second[x][y++] = matrix[j][k];
                }
            }
            x++;
            y = 0;
        }

        ans += matrix[0][i] * determinantOfMatrixHelper(n - 1, second) * ((i & 1) ? -1 : 1);
    }

    return ans;
}

int determinantOfMatrix(int n, int matrix[][n]) {
    return determinantOfMatrixHelper(n, matrix);
}


//{ Driver Code Starts.

int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int n;
		scanf("%d", &n);
		int matrix[n][n];
	 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		
		int result = determinantOfMatrix(n, matrix);
		printf("%d", result);
		printf("\n");
	}
	return 0;
}
// } Driver Code Ends