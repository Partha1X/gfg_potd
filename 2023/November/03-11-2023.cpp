/*

Author : Partha Biswas
Date : 03/11/2023
Problem : Pythagorean Triplet
Problem Link : https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	      unordered_set<int> squares;

        for (int i = 0; i < n; i++) {
            squares.insert(arr[i] * arr[i]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum_of_squares = arr[i] * arr[i] + arr[j] * arr[j];
                if (squares.find(sum_of_squares) != squares.end()) {
                    return true;
                }
            }
        }

        return false;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends