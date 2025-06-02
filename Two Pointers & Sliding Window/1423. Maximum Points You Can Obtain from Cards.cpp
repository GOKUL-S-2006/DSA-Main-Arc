class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int lsum=0;
        int rsum=0;
        for(int i=0;i<k;i++)
        {
         lsum+=nums[i];
        }
        int maxsum=lsum;
        int ri=nums.size()-1;
        for(int i=k-1;i>=0;i--)
        {
            lsum=lsum-nums[i];
            rsum+=nums[ri];
            ri--;
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};
TC:O(2K);
SC:O(1)
Idea:
Caluclate left sum and right sum and find the maxsum
