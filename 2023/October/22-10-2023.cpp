/*

Author : Partha Biswas
Date : 22/10/2023
Problem : Number of paths
Problem Link : https://practice.geeksforgeeks.org/problems/number-of-paths0926/1

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    long long  numberOfPaths(int M, int N)
    {
        // Code Here
          return nCr(M + N - 2, M - 1);
    }
    
    long long nCr(int n, int r) {
        const int MOD = 1000000007;
        if (r > n - r) {
            r = n - r; // Choose the smaller of r and n-r for optimization
        }
        
        long long result = 1;
        for (int i = 0; i < r; i++) {
            result = (result * (n - i)) % MOD;
            result = (result * modInverse(i + 1, MOD)) % MOD;
        }
        
        return result;
    }
    
    long long modInverse(int a, int m) {
        long long m0 = m;
        long long x0 = 0, x1 = 1;
        
        while (a > 1) {
            long long q = a / m;
            long long t = m;
            
            m = a % m;
            a = t;
            t = x0;
            
            x0 = x1 - q * x0;
            x1 = t;
        }
        
        if (x1 < 0) {
            x1 += m0;
        }
        
        return x1;
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends