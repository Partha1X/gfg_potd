/*

Author : Partha Biswas
Date : 05/11/2023
Problem : Top K Frequent Elements in Array - | 
Problem Link : https://www.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) 
    {
        // Code here
        map<int, int> mp;
        vector<pair<int, int>> ans;
        vector<int> rans;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it: mp){
            ans.push_back(make_pair(it.second, it.first));
        }
        sort(ans.begin(), ans.end());
        int n = ans.size();
        for(int i=n-1; i>(n-k-1); i--){
            rans.push_back(ans[i].second);
        }
        return rans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends