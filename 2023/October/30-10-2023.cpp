/*

Author : Partha Biswas
Date : 30/10/2023
Problem : Sum of XOR of all pairs 
Problem Link : https://practice.geeksforgeeks.org/problems/sum-of-xor-of-all-pairs0723/1
*/

//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
    	 long long int result = 0;
        for (int i = 0; i < 32; i++) {
            long long int countSetBits = 0;
            long long int twos = 1LL << i;
            for (int j = 0; j < n; j++) {
                if (arr[j] & twos) {
                    countSetBits++;
                }
            }
            result += (twos * countSetBits * (n - countSetBits));
        }
        return result;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends