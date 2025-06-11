class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(!st.empty() && s[i]=='*')
            {
                st.pop();
            }
            if(s[i]!='*')
            {
            st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
