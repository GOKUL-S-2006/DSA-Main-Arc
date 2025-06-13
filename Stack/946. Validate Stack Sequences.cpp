class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int i=0;
        int j=0;
        while(i<pushed.size() && j<popped.size())
        {
            st.push(pushed[i]);
            while(!st.empty() && st.top()==popped[j])
            {
                j++;
                st.pop();
            }
            i++;
        }
        return st.empty()==true?true:false;
    }
};
TC:O(N)
SC:O(N)
