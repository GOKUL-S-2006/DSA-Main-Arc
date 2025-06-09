//note:All are same pattern for count L9 all are same pattern using func(arr,k)-func(arr,k-1) that's all 
Brute Force:(TC->O(N2),SC->O(N))
    ->Generate all possible subarray


📌 Theoretical Explanation — Step-by-Step
1. Sliding Window Technique
We use a window [left, right] and maintain a hashmap freq to track the frequency of elements in the window.

2. Counting Subarrays with ≤ k Distinct
If freq.size() exceeds k, we move left forward to remove elements and restore the constraint.

For each position right, the number of valid subarrays is right - left + 1 (all subarrays ending at right and starting from left to right).

3. Count Exactly k Distinct
Use the fact:
count(==k) = count(≤k) - count(≤k-1)


Optimal code:

class Solution {
public:
    // Helper function to count subarrays with at most k distinct integers
    int countSubarraysWithAtMostKDistinct(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freq; // Frequency map to count distinct elements
        int left = 0, right = 0, count = 0;

        while (right < n) {
            freq[arr[right]]++; // Include current element in window

            // Shrink window if we have more than k distinct elements
            while (freq.size() > k) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0)
                    freq.erase(arr[left]); // Remove completely
                left++;
            }

            // Add number of subarrays ending at 'right' with ≤ k distinct
            count += right - left + 1;
            right++;
        }

        return count;
    }

    // Main function to return number of subarrays with exactly k distinct elements
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubarraysWithAtMostKDistinct(nums, k) - 
               countSubarraysWithAtMostKDistinct(nums, k - 1);
    }
};
//TC->O(2N)
//SC->O(N)
