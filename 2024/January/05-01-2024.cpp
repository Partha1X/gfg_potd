/*

Author : Partha Biswas
Date : 05/01/2024
Problem : Count possible ways to construct buildings
Problem Link : https://www.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    const int mod = 1e9 + 7; //1000000007;
        long long prev = 1, curr = 1;

        for (int i = 0; i < N; ++i) {
            int temp = curr;
            curr = (prev + curr) % mod;
            prev = temp;
        }

        return ((curr % mod) * (curr % mod)) % mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends