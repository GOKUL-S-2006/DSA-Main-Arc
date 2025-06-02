class Solution {
public:
    int minDeletions(string s) {
        map<char,int>mpp;
        for(auto x:s)
        {
            mpp[x]++;
        }
        set<int>st;
     
        int deletions = 0;
        for(auto x:mpp)
        {
           int count=x.second;

           while (count > 0 && st.find(count) != st.end()) {
                count--;
                deletions++;
            }
            if (count > 0) {
                st.insert(count);
            }
        }
        
        return deletions;
    }
};
✅ Overall Time Complexity: O(n)

💾 Space Complexity:
map<char, int> freq → stores up to 26 characters → O(1) (constant, since character set is limited).

set<int> usedFrequencies → stores up to n values in worst case → O(n)

✅ Overall Space Complexity: O(n)


