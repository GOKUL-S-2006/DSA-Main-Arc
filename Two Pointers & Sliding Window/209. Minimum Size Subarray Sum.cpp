

✅ Algorithm Explanation (Sliding Window)
You are using the two pointers technique, also called the sliding window approach.

Steps:
Initialize:

l = 0: left pointer of window.

r = 0: right pointer of window.

sum = 0: sum of current window.

minlen = INT_MAX: to store minimum length found.

Expand the window:

Move the right pointer r to include more elements in the window.

Add nums[r] to sum.

Shrink the window:

While sum ≥ target, this window is valid.

Update minlen to the smaller of current minlen or r - l + 1.

Try to shrink the window from the left (increment l) to see if you can get a smaller valid window.

Subtract nums[l] from sum.

Continue until right pointer reaches the end.

If no valid window was found (minlen is still INT_MAX), return 0. Else, return minlen.


Optimal Code:
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    
    int left = 0;           // Left pointer of the window
    int right = 0;          // Right pointer of the window
    int sum = 0;            // Current sum of the window
    int minLen = INT_MAX;   // To store the minimum length of a valid subarray

    // Iterate through the array using the right pointer
    while (right < n) {
        sum += nums[right];

        // Shrink the window from the left while the sum is >= target
        while (sum >= target) {
            minLen = min(minLen, right - left + 1);  // Update minimum length
            sum -= nums[left];   // Remove the leftmost element
            left++;              // Move the left pointer to the right
        }

        right++;  // Expand the window by moving the right pointer
    }

    // If no valid window was found, return 0
    return (minLen == INT_MAX) ? 0 : minLen;
}
//TC->O(2N)
//SC->O(1)
