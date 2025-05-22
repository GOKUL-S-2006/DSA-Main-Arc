Brute Force
TC:O(N log N)
SC:O(N);
code:
class Solution {
public:
    int findMin(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        vector<int>arr(s.begin(),s.end());
         int low=0;
        int high=arr.size()-1;
       
        while(low<high)
        {
            int mid=(low+high)/2;
            
            if(arr[mid]<arr[high])
            {
              
                high=mid;
            }
            else
            {
                low=mid+1;
                
            }
        }
        return arr[low];
    }
};
OPTIMIZED:
TC:O(LOG N)
SC:O(1)
  code:
class Solution {
public:
    int findMin(vector<int>& arr) {
       
         int low=0;
        int high=arr.size()-1;
       
        while(low<high)
        {
            int mid=(low+high)/2;
            
            if(arr[mid]<arr[high])
            {
              
                high=mid;
            }

            else if(arr[mid]>arr[high])
            {
                low=mid+1;
                
            }
            else
            {
                high--;
            }
        }
        return arr[low];
    }
};
