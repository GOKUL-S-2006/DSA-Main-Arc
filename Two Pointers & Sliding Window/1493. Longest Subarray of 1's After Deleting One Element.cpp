class Solution {
public:
Same as Max consectuvive ones the diffrerent is you can flip only one time
    int longestSubarray(vector<int>& nums) {
          int l=0;
        int r=0;
        int k=1;
        int maxlen=0;
        int n=nums.size();
        int zeroes_count=0;
        while(r<n)
        {
            if(nums[r]==0) zeroes_count++;
            while(zeroes_count>k)
            {
                if(nums[l]==0) zeroes_count--;
                l++;
            }
            if(zeroes_count<=k)
            {
                maxlen=max(maxlen,r-l+1);
            }
            r++;

        }
        return maxlen-1;
        AS WE ARE DELETING THAT ZERO WE DO NOT CONSIDER IT
    }
};
