Time Complexity:
- Worst-case: O(n²)
- Average-case: O(n log n)
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int m=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            
           while(nums[i]<=nums[i-1])
           {
             m++;
             nums[i]+=1;
           }

        }
        return m;
    }
};
Time Complexity: O(n log n) — dominated by the sorting step.
Space Complexity: O(1)
  class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int m=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            
           if(nums[i]<=nums[i-1])
           {
             m+=abs(nums[i]-nums[i-1])+1;
             nums[i]=nums[i-1]+1;
            
           }

        }
        return m;
    }
};

  
