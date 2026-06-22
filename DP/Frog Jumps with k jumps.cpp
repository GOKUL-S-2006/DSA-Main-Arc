#include <bits/stdc++.h>
using namespace std;

int f(int i, vector<int>& height, int k) {
    if (i == 0) return 0;

    int minv = INT_MAX;

    for (int j = 1; j <= k; j++) {
        if (i - j >= 0) {
            int jump = f(i - j, height, k) + abs(height[i] - height[i - j]);
            minv = min(minv, jump);
        }
    }

    return minv;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << f(n - 1, height, k) << endl;

    return 0;
}

Memoization(DP)

#include <bits/stdc++.h>
using namespace std;

int f(int i, vector<int>& height, int k,vector<int>&dp) {
    if (i == 0) return 0;

     if(dp[i]!=-1) return dp[i];
    int minv = INT_MAX;

    for (int j = 1; j <= k; j++) {
        if (i - j >= 0) {
            int jump = f(i - j, height, k,dp) + abs(height[i] - height[i - j]);
            minv = min(minv, jump);
        }
    }

    return dp[i]=minv;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int>dp(n,-1);

    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << f(n - 1, height, k,dp) << endl;

    return 0;
}



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(height[i] - height[i - j]));
            }
        }
    }

    cout << dp[n - 1] << endl;

    return 0;
}

Complexity
Time: O(n * k)
Space: O(n)


