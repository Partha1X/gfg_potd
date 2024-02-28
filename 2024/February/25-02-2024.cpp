/*

Author : Partha Biswas
Date : 25/02/2024
Problem : Reach a given score
Problem Link : https://www.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1
*/

//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {
    	// Your code here
    	
    	 vector<int>dp(n+1,0); 
        dp[0] = 1; 
         
        for(int i=3;i<=n;i++){ 
            dp[i] +=dp[i-3]; 
        } 
        for(int i=5;i<=n;i++){ 
            dp[i] +=dp[i-5]; 
        } 
        for(int i=10;i<=n;i++){ 
            dp[i] +=dp[i-10]; 
        } 
        return dp[n]; 
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends