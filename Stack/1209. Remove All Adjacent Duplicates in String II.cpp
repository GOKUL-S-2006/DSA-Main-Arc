class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
      
        for(int i=0;i<s.size();i++)
        {
             if (!st.empty() && st.top().first == s[i]) {
                st.top().second++;
             }
            else {
                st.push({s[i], 1});
            }

            if (st.top().second == k) {
                st.pop();
            }
        }
          string result = "";
        while (!st.empty()) {
            result.append(st.top().second, st.top().first);
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;

    }
};
