class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mpp;
        mpp[0]=1;
        int psum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            psum+=nums[i];
            int rem=psum-k;
            cnt+=mpp[rem];
            mpp[psum]+=1;
        }
        return cnt;
    }
};
