class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int pre=0;
        int c=0;
        
        map<int,int>mpp;
        mpp[0]=1;
        for(int num:nums){
            pre+=num;
            int rem=pre%k;
            if(rem<0){
                rem+=k;
            }
            if(mpp.find(rem)!=mpp.end()){
                c+=mpp[rem];

            }
            mpp[rem]++;
        }
        return c;

    }
};


