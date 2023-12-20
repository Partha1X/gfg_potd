/*

Author : Partha Biswas
Date : 18/12/2023
Problem : Game of XOR
Problem Link : https://www.geeksforgeeks.org/problems/game-of-xor1541/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int gameOfXor(int N , int A[]) {
        // code here
         int ans = 0;
        
        for(int i = 0; i < N; i++){
            if(((i + 1) & 1) and ((N - i) & 1)){
                ans ^= A[i];
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.gameOfXor(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends