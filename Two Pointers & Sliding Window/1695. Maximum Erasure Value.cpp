class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
    if (n == 1) {
        return nums[0]; // No subarray to erase
    }

    unordered_map<int, int> freq; // Use unordered_map for faster lookups
    int maxSum = 0, currSum = 0, l = 0, r = 0;

    while (r < n) {
        freq[nums[r]]++; // Increment frequency of current element
        currSum += nums[r]; // Add the element to the current sum

        // If the current element becomes non-unique (frequency > 1):
        while (freq[nums[r]] > 1) {
            freq[nums[l]]--; // Decrement frequency of leftmost element
            currSum -= nums[l]; // Subtract the leftmost element from current sum
            l++; // Slide the left window to the right
        }

        maxSum = max(maxSum, currSum); // Update maximum sum if necessary
        r++; // Slide the right window to the right
    }

    return maxSum;
    }
};
