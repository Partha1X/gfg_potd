/*

Author : Partha Biswas
Date : 05/10/2023
Problem : Count number of substrings
Problem Link : https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1
*/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int substrCount (string s, int k) {
    	//code here.
    	vector<int> freq(26, 0); // Frequency array to store character occurrences
        int uc = 0;             // Count of unique characters in the current window
        long long res = 0;      // Final result

        int l = 0;
        int r = 0;

        long long ac = 0; // Additional count for substrings with 'k' unique characters

        while (r < s.size()) {
            if (freq[s[r] - 'a'] == 0) {
                uc++;
            }
            
            freq[s[r] - 'a']++; // Increment the character frequency

            // Shrink the window until there are 'k' unique characters
            while (uc > k) {
                freq[s[l] - 'a']--;

                if (freq[s[l] - 'a'] == 0) {
                    uc--;
                }

                l++;
                ac = 0;
            }

            // If there are exactly 'k' unique characters in the window
            if (uc == k) {
                while (freq[s[l] - 'a'] > 1) {
                    ac++;
                    freq[s[l] - 'a']--;
                    l++;
                }

                // Add the additional count plus 1 to the result
                res += ac + 1;
            }

            r++;
        }

        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends
