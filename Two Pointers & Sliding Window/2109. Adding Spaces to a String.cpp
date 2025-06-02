class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int j=0;
        for(int i=0;i<s.size();i++)
        {
           
            
            if (j<spaces.size() && i==spaces[j] )
            {
                ans+=" ";
                j++;
                
            }
             ans+=s[i];


        }
        return ans;
    }
};

🧠 Time Complexity:
for loop runs once for each character in s → O(n) where n = s.size().

In the worst case, for each character, a space may be added → at most 2 operations per iteration (appending space and char).

All operations inside the loop are O(1), assuming string += char is amortized O(1) in C++.

✅ Total Time Complexity = O(n)

💾 Space Complexity:
A new string ans is created to store the result. It may contain up to n + m characters, where:

n = length of s

m = number of spaces inserted (i.e., spaces.size())

✅ Total Space Complexity = O(n + m)

✅ Final Analysis Summary:
Aspect	Complexity
Time Complexity	O(n)
Space Complexity	O(n + m)








