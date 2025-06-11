✅ Approach: Monotonic Stack
Use a stack to keep track of indices of temperatures

For each temperature:

If it is warmer than the top of the stack, then:

Pop and calculate the number of days waited

Push current index to the stack
The stack stores indices of decreasing temperatures

When we find a warmer day, we resolve the previous colder day(s)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prev = st.top();
                st.pop();
                ans[prev] = i - prev;
            }
            st.push(i);
        }

        return ans;
    }
};



 Time Complexity: O(n)
 Space Complexity: O(n)
