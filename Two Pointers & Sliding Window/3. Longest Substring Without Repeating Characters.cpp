Brute Force:
#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubstr(string &s)
{
    int n = s.size();
    int res = 0;

    for (int i = 0; i < n; i++)
    {

        // Initializing all characters as not visited
        vector<bool> vis(26, false);

        for (int j = i; j < n; j++)
        {

            // If current character is visited
            // Break the loop
            if (vis[s[j] - 'a'] == true)
                break;

            // Else update the result if this window is larger,
            // and mark current character as visited.
            else
            {
                res = max(res, j - i + 1);
                vis[s[j] - 'a'] = true;
            }
        }
    }
    return res;
}

int main()
{
    string s = "geeksforgeeks";
    cout << longestUniqueSubstr(s);
    return 0;
}
Time Complexity: O(n*26), the outer loop runs O(n) time, and the inner loop runs in O(26) in the worst case (considering all unique characters), resulting in a total time complexity of O(n*26).
Auxiliary Space: O(1), vis array has size 26 which is constant.




Optimized:

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,-1);
        int n=s.size();
        int l=0;
        int r=0;
        int len=0;
        int maxlen=0;
        while(r<n)
        {
            if(hash[s[r]]!=-1)
            {
                if(hash[s[r]]>=l)
                {
                    l=hash[s[r]]+1;
                }
            }
            len=r-l+1;
            maxlen=max(maxlen,len);
            hash[s[r]]=r;
            r++;
        }
        return maxlen;
    }
    
};
TC:O(N)
SC:O(1)
