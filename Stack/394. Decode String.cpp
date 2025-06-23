class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        
        for (char ch : s) {
            if (ch != ']') {
                st.push(ch);
            } else {
                // 1. Pop substring inside '['
                string decoded;
                while (!st.empty() && st.top() != '[') {
                    decoded = st.top() + decoded;
                    st.pop();
                }
                st.pop(); // remove '['
                
                // 2. Pop digits to form repeat count
                string numStr;
                while (!st.empty() && isdigit(st.top())) {
                    numStr = st.top() + numStr;
                    st.pop();
                }
                int k = stoi(numStr);
                
                // 3. Repeat substring and push back into stack
                string repeated;
                for (int i = 0; i < k; ++i)
                    repeated += decoded;
                for (char c : repeated)
                    st.push(c);
            }
        }
        
        // Build final decoded string
        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};
