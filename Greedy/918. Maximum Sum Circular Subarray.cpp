✅ Code:
cpp
Copy
Edit
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;

        for (int start = 0; start < n; ++start) {
            int currSum = 0;
            for (int len = 0; len < n; ++len) {
                int idx = (start + len) % n;  // wrap-around
                currSum += nums[idx];
                maxSum = max(maxSum, currSum);
            }
        }

        return maxSum;
    }
};
🧠 Time Complexity:
Outer loop: O(n)

Inner loop: O(n)

Total: O(n²)



