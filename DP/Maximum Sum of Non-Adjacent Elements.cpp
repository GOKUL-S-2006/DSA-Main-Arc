#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int index) {
    if (index < 0) return 0;
    if (index == 0) return arr[index];
    // Include current element
    int take = arr[index] + solve(arr, index - 2);

    // Exclude current element
    int skip = solve(arr, index - 1);

    return max(take, skip);
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};

    int maxSum = solve(arr, arr.size() - 1);

    cout << maxSum << endl;

    return 0;
}

TC:O(2^N)
Space O(n) (recursion stack)

Memoization code:

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int index, vector<int>& dp) {
    if (index < 0) return 0;
    if (index == 0) return arr[index];

    if (dp[index] != -1) return dp[index];

    int take = arr[index] + solve(arr, index - 2, dp);
    int skip = solve(arr, index - 1, dp);

    return dp[index] = max(take, skip);
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int n = arr.size();

    vector<int> dp(n, -1);

    cout << solve(arr, n - 1, dp) << endl;

    return 0;
}


TC:O(N)
SC:O(N)+O(N)

Tabulation Code

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int n = arr.size();

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 1) {
        cout << arr[0] << endl;
        return 0;
    }

    vector<int> dp(n);

    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        int take = arr[i] + dp[i - 2];
        int skip = dp[i - 1];
        dp[i] = max(take, skip);
    }

    cout << dp[n - 1] << endl;

    return 0;
}


Space Optimized Version


#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int n = arr.size();

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 1) {
        cout << arr[0] << endl;
        return 0;
    }

    int prev2 = arr[0];                      // dp[i-2]
    int prev1 = max(arr[0], arr[1]);        // dp[i-1]

    for (int i = 2; i < n; i++) {
        int take = arr[i] + prev2;
        int skip = prev1;

        int curr = max(take, skip);

        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1 << endl;

    return 0;
}



⏱ Time: O(n) (same as before)
🧠 Space: O(1) (optimized from O(n))



