/*

Author : Partha Biswas
Date : 17/01/2024
Problem : All Unique Permutations of an array
Problem Link : https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        set<vector<int>>ans; 
       sort(arr.begin(),arr.end()); 
       ans.insert(arr); 
       while(1) 
       { 
           next_permutation(arr.begin(),arr.end()); 
           ans.insert(arr); 
           bool flag = true; 
           for(int i=0;i<n-1;i++) 
           { 
               if(arr[i+1]>arr[i]) 
               { 
                   flag = false; 
               } 
                
           } 
           if(flag) 
           { 
               break; 
           } 
       } 
       vector<vector<int>>res; 
       for(auto i:ans) 
       { 
           res.push_back(i); 
       } 
       return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends