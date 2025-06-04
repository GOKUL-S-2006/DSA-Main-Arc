class Solution {
public:
     //key idea:
     //   Take two pointers l,r
     //Move the r pointer while moving when you encounter a 0 add zeros cnt
     //whenever the zero count>k then don't allow the current window size to grow until zeros cnt<=k 
    int longestOnes(vector<int>& nums, int k) {
        
        int n=nums.size();

        int l=0,r=0,zeros=0,maxlen=0;

        while(r<n){

            if(nums[r]==0)zeros++;

            if(zeros>k){

                if(nums[l]==0)zeros--;
                l++;
            }

            if(zeros<=k){
                maxlen=max(maxlen,r-l+1);
            }

            r++;
        }

        return maxlen;
    }
};

TC->O(N)
SC->O(1)
