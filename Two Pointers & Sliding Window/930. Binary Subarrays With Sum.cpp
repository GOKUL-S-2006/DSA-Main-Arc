Main Function: numSubarraysWithSum(nums, goal)
Objective: Count the number of subarrays in nums whose sum is exactly equal to goal.
  
Approach:
Use a helper function countsubarrylessthanorequalk(nums, k) to count subarrays whose sum is less than or equal to k.

✅ Steps:
Initialize:

l = 0 → left pointer of window

r = 0 → right pointer of window

sum = 0 → current sum of the window

cnt = 0 → count of valid subarrays

Loop while r < n (iterate through the array with r):

Add nums[r] to sum.

While sum > k:

Subtract nums[l] from sum.

Move left pointer l to the right.

At this point, all subarrays between l and r (inclusive) have sum ≤ k.

So, add r - l + 1 to cnt.

Move r one step right.

Return cnt → total number of subarrays with sum ≤ k.


BruteForce solution:(TC->O(N2),SC->O(1))
        ->Generate all subarray and cnt the answer and return 

Better soltuion:(idea:count subarray sum==k problem from array)(TC->O(N),SC->O(N))
        ->Using HashMap store the sum till i th  index subtract sum-k check the map that sum-k is there in the map if so add that to cnt and add current sum mpp[sum]++
  

Optimal solution:(idea:count subarray sum==k problem from array)

//This is simple mathematics if someone doesnot understand

     //findingSum(nums, 2) counts all subarrays where sum is 0, 1, or 2

     //findingSum(nums, 1) counts all subarrays where sum is 0 or 1
    int countsubarrylessthanorequalk(vector<int>& arr,int k){

        int n=arr.size();

        int cnt=0,l=0,r=0,sum=0;

        while(r<n){
              sum+=arr[r];

              while(sum>k && l<=r){
                sum-=arr[l];
                l++;
              }

              cnt+=r-l+1;
              r++;
        }
      return cnt;
    } 
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return countsubarrylessthanorequalk(nums,goal)-countsubarrylessthanorequalk(nums,goal-1);
        
}

TC->0(2N)
SC->O(N)

Similar problem:1248. Count Number of Nice Subarrays
