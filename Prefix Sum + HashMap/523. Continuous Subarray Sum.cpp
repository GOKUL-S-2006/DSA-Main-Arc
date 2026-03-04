class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       int pre = 0;
        unordered_map<int, int> mpp;
        mpp[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            int rem = pre % k;

            if (mpp.find(rem) != mpp.end()) {
                if (i - mpp[rem] >= 2)
                    return true;
            } else {
                mpp[rem] = i;
            }
        }
        return false;
    }
};
