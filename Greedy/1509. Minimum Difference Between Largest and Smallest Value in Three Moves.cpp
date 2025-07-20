class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;

        sort(nums.begin(), nums.end());

        int option1 = nums[n - 4] - nums[0];   // remove 3 largest
        int option2 = nums[n - 3] - nums[1];   // remove 2 largest, 1 smallest
        int option3 = nums[n - 2] - nums[2];   // remove 1 largest, 2 smallest
        int option4 = nums[n - 1] - nums[3];   // remove 3 smallest

        return min({option1, option2, option3, option4});
    }
};
