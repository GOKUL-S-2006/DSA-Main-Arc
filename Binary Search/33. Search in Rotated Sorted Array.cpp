class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
             if(nums[mid]==target)
             {
                return mid;
             }
             //If Left Half is Sorted
            if(nums[mid]>=nums[low] )
             {
                //Checking if target lies within this bound
                if(target<=nums[mid] && target>=nums[low])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
             }
            //If Right Half is Sorted
             else
             {
                //if the target lies withint the bounf mid to High
                if(nums[mid]<=target  && target<=nums[high])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
             }
        }
        return -1;
    }
};
TC:O(Log N)
SC:O(1)
