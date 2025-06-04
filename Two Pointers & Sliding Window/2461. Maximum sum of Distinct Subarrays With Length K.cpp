class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxsum = 0;
        long long cursum = 0;
        int l = 0, r = 0;  // Initialize `l`
        map<int, int> mp;

        while (r < nums.size()) {
            mp[nums[r]]++;
            cursum += nums[r];

            // If the window size exceeds `k`, shrink it
            while (r - l + 1 > k) {
                cursum -= nums[l];
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                l++;
            }

            // If the window size is exactly `k` and contains unique elements
            if (r - l + 1 == k && mp.size() == k) {
                maxsum = max(maxsum, cursum);
            }

            r++;
        }

        return maxsum;
    }
};
