class Solution {
      //key idea:
      //Take two pointers r,l
      // Move the r pointer while moving make sure sum+=arr[r] then mark that element in map that you have already seen 
      // After doing that using another while loop check that you have exceeds the window size k or are you using the same element again if so them decrement the l pointer
      //while decrementing check do these three things
      // sum-=nums[l];
      // mpp[nums[l]]--;
      //l++;
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
     
     int n=nums.size();
    
     long long sum=0,maxlen=0;
    
     int l=0,r=0;

     unordered_map<int,int> mpp;

     while(r<n){

        mpp[nums[r]]++;
        sum+=nums[r];

         while(r-l+1>k || mpp[nums[r]]>1){
                   sum-=nums[l];
                   mpp[nums[l]]--;
                   l++;
        }

        if(r-l+1==k)maxlen=max(maxlen,sum);

        r++;
     }
     
     return maxlen;
    }
};

TC->O(2N)
SC->O(K);
