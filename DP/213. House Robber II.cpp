class Solution {
public:
    int solve(vector<int>& arr, int index, vector<int>& dp) {
        if (index < 0) return 0;
        if (index == 0) return arr[index];

        if (dp[index] != -1) return dp[index];

        int take = arr[index] + solve(arr, index - 2, dp);
        int skip = solve(arr, index - 1, dp);

        return dp[index] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];  // edge case

        vector<int> temp1, temp2;

        for (int i = 0; i < n; i++) {
            if (i != 0) temp1.push_back(nums[i]);     // exclude first
            if (i != n - 1) temp2.push_back(nums[i]); // exclude last
        }

        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);

        int ans1 = solve(temp1, temp1.size() - 1, dp1);
        int ans2 = solve(temp2, temp2.size() - 1, dp2);

        return max(ans1, ans2);
    }
};
