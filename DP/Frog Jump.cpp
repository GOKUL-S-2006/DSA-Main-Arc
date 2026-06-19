int f(int i, vector<int>& height) {
    if (i == 0) return 0;

    int jump1 = f(i - 1, height) + abs(height[i] - height[i - 1]);

    int jump2 = INT_MAX;
    if (i > 1)
        jump2 = f(i - 2, height) + abs(height[i] - height[i - 2]);

    return min(jump1, jump2);
}

⚠️ Problem with Pure Recursion
Time Complexity: O(2^n) (very slow)
Repeated calculations (overlapping subproblems)

memoization (Top-Down DP).

int f(int i, vector<int>& height, vector<int>& dp) {
    if (i == 0) return 0;

    if (dp[i] != -1) return dp[i];

    int jump1 = f(i - 1, height, dp) + abs(height[i] - height[i - 1]);

    int jump2 = INT_MAX;
    if (i > 1)
        jump2 = f(i - 2, height, dp) + abs(height[i] - height[i - 2]);

    return dp[i] = min(jump1, jump2);
}

Complexity
Time: O(n)
Space: O(n) (dp + recursion stack)


Tabulation(Bottom-up)


int frogJump(vector<int>& height) {
    int n = height.size();
    vector<int> dp(n);

    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        int jump1 = dp[i - 1] + abs(height[i] - height[i - 1]);

        int jump2 = INT_MAX;
        if (i > 1)
            jump2 = dp[i - 2] + abs(height[i] - height[i - 2]);

        dp[i] = min(jump1, jump2);
    }

    return dp[n - 1];
}




Space Optimized Version


int frogJump(vector<int>& height) {
    int n = height.size();

    int prev2 = 0; // dp[i-2]
    int prev1 = 0; // dp[i-1]

    for (int i = 1; i < n; i++) {
        int jump1 = prev1 + abs(height[i] - height[i - 1]);

        int jump2 = INT_MAX;
        if (i > 1)
            jump2 = prev2 + abs(height[i] - height[i - 2]);

        int curr = min(jump1, jump2);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
