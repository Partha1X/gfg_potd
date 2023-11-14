/*

Author : Partha Biswas
Date : 14/11/2023
Problem : Shortest Common Supersequence
Problem Link : https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
*/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
         vector<int> dp(n+1) ;
        
        for(int i=0;i<=n;i++)
        dp[i] = i ;
        
        int prev = 0 ;
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(j==0)
                {
                prev = dp[j] ;
                dp[j] = dp[j]+1;
                continue;
                }
                
                int cur = dp[j] ;
                
                if(X[i-1] == Y[j-1])
                    dp[j] = min(1+prev,1+min(dp[j-1],dp[j])) ;
                else
                    dp[j] = 1+min(dp[j-1],dp[j]) ;
                    
                prev = cur ;
                
            }
            
        }
        
        return dp[n] ;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends