// CPP implementation of above approach
#include <bits/stdc++.h>
using namespace std;

// Function to return required minimum sum
int sumSubarrayMins(int A[], int n)
{
    // To store answer
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // To store minimum element
        int min_ele = A[i];
        for (int j = i; j < n; j++) {
            // Finding minimum element of subarray
            min_ele = min(min_ele, A[j]);
            // Adding that minimum element of subarray in
            // answer
            ans += min_ele;
        }
    }
    return ans;
}

// Driver program
int main()
{
    int A[] = { 3, 1, 2, 4 };
    int n = sizeof(A) / sizeof(A[0]);
    // function call to get required result
    cout << sumSubarrayMins(A, n);

    return 0;
}
Time Complexity:O(N2),because of two nested for loops 
Space Complexity:O(1)

class Solution {
public:
    const int MOD = 1e9 + 7;

    // Function to compute previous smaller elements
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

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev = getPrevSmaller(arr);
        vector<int> next = getNextSmaller(arr);

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            res = (res + (arr[i] * left % MOD) * right % MOD) % MOD;
        }

        return res;
    }
};
Complexity Analysis:

Time Complexity:O(N), where N is the length of A. 
Space Complexity:O(N).

Note:
So why assign n if the stack is empty?
Because:

If no smaller element is found to the right of arr[i], then arr[i] is the smallest until the end of the array.

So its "next smaller" element is beyond the end, which we denote using n.
