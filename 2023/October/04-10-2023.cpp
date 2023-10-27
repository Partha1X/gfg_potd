/*

Author : Partha Biswas
Date : 04/10/2023
Problem : Roman Number to Integer
Problem Link : https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1
*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
         map<char,int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        int ans = 0;
        
        int n = str.size(); // Updated variable name from s to str
        // Loop through the input string to convert Roman numerals to an integer
        for(int i = 0; i < n; i++)
        // Subtract if a smaller numeral appears before a larger one (e.g., IV = 4)
        {
            if(i + 1 < n and mp[str[i]] < mp[str[i + 1]]){ // Updated variable name from s to str
                ans -= mp[str[i]]; // Updated variable name from s to str
            }
            else
             // Add if the numeral is equal or smaller than the next numeral (e.g., VIII = 8).

            {
                ans += mp[str[i]]; // Updated variable name from s to str
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends
