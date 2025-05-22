#include <bits/stdc++.h>
using namespace std;

int minCandy(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0; // Edge case

    vector<int> leftcandy(n, 1);
    vector<int> rightcandy(n, 1);

    // Left pass
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
            leftcandy[i] = leftcandy[i - 1] + 1;
    }

    // Right pass
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
            rightcandy[i] = rightcandy[i + 1] + 1;
    }

    // Calculate final answer
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += max(leftcandy[i], rightcandy[i]); // Take max at each position
    }

    return ans;
}

int main()
{
    vector<int> arr = {15, 40, 32, 12, 17, 23};

    cout << minCandy(arr);
}
