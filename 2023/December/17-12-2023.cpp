/*

Author : Partha Biswas
Date : 17/12/2023
Problem : Max Sum without Adjacents
Problem Link : https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	      vector<int> dp(n,0);
     dp[0]=arr[0];
     dp[1]=max(arr[0],arr[1]);
     for(int i=2;i<n;i++)
     {
         int a=dp[i-1];
         int b=arr[i]+dp[i-2];
         
         dp[i]=max(a,b);
     }
     return dp[n-1];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends