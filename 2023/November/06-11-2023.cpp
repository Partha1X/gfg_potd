/*

Author : Partha Biswas
Date : 06/11/2023
Problem : Letters Collection
Problem Link : https://www.geeksforgeeks.org/problems/c-letters-collection4552/1
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        // code here
          vector<int>v;
        
        for(int k=0;k<q;k++)
        {
            int hop= queries[k][0];
            int sum=0;
            int r= queries[k][1];
            int c= queries[k][2];
            
                for(int i= -hop;i<=hop;i++)
                {
                    for(int j= -hop;j<=hop;j++)
                    {
                        if( r+i>=0 && c+j>=0 && r+i<n                                                                                            && c+j <m && (abs(i)==hop || abs(j)==hop))
                        {
                            sum+= mat[r+i][c+j];
                        }
                    }
                }
                v.push_back(sum);
            
            
        }
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, q, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>q;
        vector<int> queries[q];
        for(int k = 0;k < q;k++){
            cin>>ty>>i>>j;
            queries[k].push_back(ty);
            queries[k].push_back(i);
            queries[k].push_back(j);
        }
        
        Solution ob;
        vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends