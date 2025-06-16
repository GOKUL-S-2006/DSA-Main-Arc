class Solution {
public:
    vector<int> previousGreaterIndex(vector<int>& arr) {
    int n = arr.size();
    vector<int> prev(n, -1);
    stack<int> st; // will store indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            prev[i] = st.top(); // index of previous greater
        }

        st.push(i);
    }

    return prev;
}

vector<int> nextGreaterIndex(vector<int>& arr) {
    int n = arr.size();
    vector<int> next(n, -1);
    stack<int> st; // will store indices

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            next[i] = st.top(); // index of next greater
        }

        st.push(i);
    }

    return next;
}
    vector<int> getPrevSmaller(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> prev(n);

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return prev;
    }

    // Function to compute next smaller elements
    vector<int> getNextSmaller(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> next(n);

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return next;
    }

    long long subArrayRanges(vector<int>& arr) {
          int n = arr.size();
    vector<int> prev = getPrevSmaller(arr);
    vector<int> next = getNextSmaller(arr);
    vector<int> prevg = previousGreaterIndex(arr);
    vector<int> nextg = nextGreaterIndex(arr);

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        long long left = prev[i] == -1 ? i + 1 : i - prev[i];
        long long right = next[i] == n ? n - i : next[i] - i;

        long long leftg = prevg[i] == -1 ? i + 1 : i - prevg[i];
        long long rightg = nextg[i] == -1 ? n - i : nextg[i] - i;

        res += (leftg * rightg - left * right) * (long long)arr[i];
    }

    return res;
    }
};

Time Complexity	O(n)
Space Complexity	O(n)
