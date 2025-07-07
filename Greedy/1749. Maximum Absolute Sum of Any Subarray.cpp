class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
         int cursum = 0;
        int min_pre = 0, max_pre = 0;
        int res = 0;
        for(int i=0;i<nums.size();i++){
            cursum+=nums[i];
            res=max({res,abs(cursum-min_pre),abs(cursum-max_pre)});
            min_pre=min(min_pre,cursum);
            max_pre=max(max_pre,cursum);
        }
        return res;
    }
};
