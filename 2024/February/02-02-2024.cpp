/*

Author : Partha Biswas
Date : 02/01/2024
Problem : Implement Atoi
Problem Link : https://www.geeksforgeeks.org/problems/implement-atoi/1
*/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
         bool negative = false;
        int ans = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '-' && i == 0) {
                negative = true;
            } else if (s[i] <= '9' && s[i] >= '0') {
                ans = ans * 10 + (s[i] - '0');
            } else {
                return -1;
            }
        }
        
        if (negative) {
            return -ans;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends