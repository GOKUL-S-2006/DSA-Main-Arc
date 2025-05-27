class Solution {
public:
    int blackbox(vector<int> &nums,int n)
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {

             sum+=ceil((double)nums[i]/(double)n);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
       
        int l=1;
       
        int r=*max_element(nums.begin(),nums.end());
         int ans=r;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(blackbox(nums,mid)<=threshold)
           {
                    ans=mid;
                    r=mid-1;

           }
           else {
             
              l=mid+1;
              
             
           }
           

        }
        return ans;
    }
};
