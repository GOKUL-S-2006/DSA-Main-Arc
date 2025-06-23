class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        
        for (char ch : s) {
            if (ch != ')') {
                st.push(ch);
            } else {
                // 1. Pop substring inside '('
                string decoded;
                while (!st.empty() && st.top() != '(') {
                    decoded = st.top() + decoded;
                    st.pop();
                }
                st.pop(); // remove '('
                reverse(decoded.begin(),decoded.end());
                for (char c : decoded)
                    st.push(c);
            }
        }
        
        // Build final  string
        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};
