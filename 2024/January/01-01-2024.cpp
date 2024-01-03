/*

Author : Partha Biswas
Date : 01/01/2024
Problem : Array Pair Sum Divisibility Problem
Problem Link : https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
*/

//{ Driver Code Starts
/*
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
          if (nums.size() % 2 != 0) { 
            return false;  // If the array size is odd, we can't form pairs 
        } 
 
        unordered_map<int, int> freq; 
        for (int num : nums) { 
            int remainder = num % k; 
            freq[remainder]++; 
        } 
 
        for (int num : nums) { 
            int remainder = num % k; 
            if (2 * remainder == k) { 
                if (freq[remainder] % 2 != 0) { 
                    return false;  // If the frequency of such numbers is odd, we can't form pairs 
                } 
            } else if (remainder == 0) { 
                if (freq[remainder] % 2 != 0) { 
                    return false;  // If the frequency of such numbers is odd, we can't form pairs 
                } 
            } else { 
                if (freq[remainder] != freq[k - remainder]) { 
                    return false;  // If the frequencies of complements are not equal, we can't form pairs 
                } 
            } 
        } 
 
        return true; 
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
*/