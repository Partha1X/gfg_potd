/*

Author : Partha Biswas
Date : 03/10/2023
Problem : Column name from a given column number
Problem Link : https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
       string ans="";
       // Process the column number
       while(n){
            long long int m=n%26;
            n/=26;
            if(m==0){
                ans+='Z';
                n--;
            }
            else{
                char c='A'+m-1;
                ans+=c;
            }
        } 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends
