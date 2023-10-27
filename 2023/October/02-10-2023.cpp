/*

Author : Partha Biswas
Date : 02/10/2023
Problem : Number of distinct subsequences
Problem Link : https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	     const int mod = 1e9 + 7; // Define and initialize mod for taking the result modulo

        // Initialize an array
        vector<int> check(256, -1);

        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // String with 0 size has 1 subsequence i.e. ""

        for (int i = 1; i <= n; i++) 
        {
            dp[i] = (2 * dp[i - 1]) % mod; 

            if (check[s[i - 1]] != -1) 
            {
                // Subtract the count of subsequences that contain the character at its last occurrence
                dp[i] = (dp[i] - dp[check[s[i - 1]]] + mod) % mod;
            }
            check[s[i - 1]] = i - 1;
        }
        return dp[n] % mod; // Return the result modulo mod
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends
