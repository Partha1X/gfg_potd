/*

Author : Partha Biswas
Date : 22/02/2024
Problem : Distinct occurrences
Problem Link : https://www.geeksforgeeks.org/problems/distinct-occurrences/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
      //Your code here
      
         int n = s.size();
        int m = t.size();
        
        // Initializing a 2D vector to store the counts of subsequences
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Base case initialization
        for (int j = 0; j <= n; ++j)
            dp[0][j] = 1; // empty string is a subsequence of any string
        
        // Iterating through t and s to fill the dp table
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (t[i - 1] != s[j - 1])
                    dp[i][j] = dp[i][j - 1]; // If characters don't match, take the count from the previous character in s
                else
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % 1000000007; // Otherwise, add the counts from previous character in s and previous character in t
            }
        }
        
        return dp[m][n]; // Return the count of subsequences of t in s
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends