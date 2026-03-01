#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    multiset<long long> left, right;

    int l = 0, r = 0;

    while (r < n) {
        // insert a[r]
        if (left.empty() || a[r] <= *prev(left.end()))
            left.insert(a[r]);
        else
            right.insert(a[r]);

        // balance
        while (left.size() > right.size() + 1) {
            right.insert(*prev(left.end()));
            left.erase(prev(left.end()));
        }
        while (right.size() > left.size()) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }

        // window size reached
        if (r - l + 1 == k) {
            // print median (smaller one for even k)
            cout << *prev(left.end()) << " ";

            // remove a[l]
            if (left.find(a[l]) != left.end())
                left.erase(left.find(a[l]));
            else
                right.erase(right.find(a[l]));

            l++;

            // rebalance after removal
            while (left.size() > right.size() + 1) {
                right.insert(*prev(left.end()));
                left.erase(prev(left.end()));
            }
            while (right.size() > left.size()) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
        }

        r++;
    }

    return 0;
}


Overall Time Complexity

O(n log k)

Overall Space Complexity

O(k)


🧠 Approach (Sliding Window Median using Multiset)

Use two multisets:

left to store the smaller half of elements

right to store the larger half of elements

Maintain the invariant:

All elements in left ≤ all elements in right

left.size() = right.size() or left.size() = right.size() + 1

The median of the window is always the maximum element of left.

For each element while sliding the window:

Insert the new element into the correct multiset.

Rebalance the multisets:

If right becomes larger, move its smallest element to left.

If left becomes larger by more than one, move its largest element to right.

When the window size becomes k:

Output the median from left.

Remove the outgoing element from the multiset it belongs to.

Rebalance again.

🎯 One-line ending (optional but impressive)

“This keeps the window split into two balanced halves, allowing the median to be retrieved in O(1) time.”


