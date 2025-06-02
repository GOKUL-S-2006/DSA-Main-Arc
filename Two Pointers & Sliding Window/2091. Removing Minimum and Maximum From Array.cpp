class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minind=0;
        int maxind=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>nums[maxind])
            {
                maxind=i;
            }
            if(nums[i]<nums[minind])
            {
                minind=i;
            }
        }
        //for reverse deleteions
        int r=0;
        if(minind>maxind)
        {
            r=n-maxind;
        }
        else
        {
            r=n-minind;
        }
        //for front deleteions
        int f=max(minind,maxind);
       

        
        //for both deleteions
        minind=min(minind+1,n-minind);
        maxind=min(maxind+1,n-maxind);
       

        return min({f+1,r,maxind+minind});
       
       

    }
};

TC:O(N)
SC;O(1);
IDEA:
We need to find the min between the front ,back,both front and back deletions;

Cleaner Version
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;

        // Find indices of min and max elements
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }

        // Ensure minIdx <= maxIdx for easier handling
        if (minIdx > maxIdx) swap(minIdx, maxIdx);

        // Three strategies:
        // 1. Delete from front up to maxIdx
        // 2. Delete from back starting from minIdx
        // 3. Delete minIdx from front and maxIdx from back
        int deleteFromFront = maxIdx + 1;
        int deleteFromBack = n - minIdx;
        int deleteBothEnds = (minIdx + 1) + (n - maxIdx);

        return min({deleteFromFront, deleteFromBack, deleteBothEnds});
    }
};

  
