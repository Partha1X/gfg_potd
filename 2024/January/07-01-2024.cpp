/*

Author : Partha Biswas
Date : 07/01/2024
Problem : Split Array Largest Sum
Problem Link : https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool isPossible(int arr[], int N, int K, long long mid) {
        int count = 1;
        long long sum = 0;

        for (int i = 0; i < N; i++) {
            sum += arr[i];
            if (sum > mid) {
                count++;
                sum = arr[i];
            }
        }

        return count <= K;
    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
         long long low = *max_element(arr, arr + N);
        long long high = accumulate(arr, arr + N, 0LL);
        long long result = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (isPossible(arr, N, K, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends