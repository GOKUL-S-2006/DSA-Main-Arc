class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int mid = 0;
        int low = 0;
        int high = nums.size()-1;
        while(low<=high)
        {
            mid = low+(high-low)/2;//OVERFLOW PREVENTING
            if(target==nums[mid])
                return mid;
            
            else
                if(nums[mid]>target)
                    high = mid-1;
            else
                low = mid+1;
        }
        return -1;
    }
};
