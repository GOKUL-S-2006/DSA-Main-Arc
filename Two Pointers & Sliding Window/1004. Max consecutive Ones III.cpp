Brute force Approach:
IDEA:
The idea is to solve the problem by generating all the substrings of an array and counting the zero element if the count of zero exceeds k then break it then move to the next substring.
class Solution {
    public int longestOnes(int[] nums, int k) {
        int max_len = 0;
        for(int i = 0;i<nums.length;i++){
            int zero = 0;
            for(int j = i;j<nums.length;j++){
                if(nums[j] == 0){
                    zero++;
                }
                if(zero <= k){
                    max_len = Math.max(max_len,j-i+1);
                }else{
                    break;
                }
            }
        }
        return max_len;     
    }
}

Time Complexity: O(n²)

Space Complexity: O(1)

Optimal Solution — 1
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int maxlen=0;
        int n=nums.size();
        int zeroes_count=0;
        while(r<n)
        {
            if(nums[r]==0) zeroes_count++;
            while(zeroes_count>k)
            {
                if(nums[l]==0) zeroes_count--;
                l++;
            }
            if(zeroes_count<=k)
            {
                maxlen=max(maxlen,r-l+1);
            }
            r++;

        }
        return maxlen;
    }
};
Time Complexity: O(2n)

Space Complexity: O(1)

IDEA:
Initialize the two variables as “left” and “right” and assign the value of these variables as Zero’th index.
Initialize another variable as “max_length” and assign its value as 0.

Move the right index one by one until the end of the array and if the element is found as 0 then increment the zero count in a separate variable as “zero_count”.
When the zero_count variable exceeds k’th variable, increment variable left +1 if the element of left index is found as 0 then decrement the zero_count.
During every iteration assign the value of max_length as (right-left+1) if the value of (right-left+1) > max_length.

  Optimal Solution — 2
In the below code, we shrunk the left most index until valid substring. But we don't need the valid substring less than max_length. To avoid this O(n) time complexity we will be using Sliding Window technique to maintain the max_length by incrementing both left and right.

class Solution {
    public int longestOnes(int[] nums, int k) {
        int max_len = 0;
        int left = 0, right = 0;
        int zero = 0;
        while(right < nums.length){
            if(nums[right] == 0){
                zero++;
            }
            if(left < right && zero > k){
                if(nums[left] == 0){
                    zero--;
                }
                left++;
            }
            if(zero <=k){
                max_len = Math.max(max_len, right-left+1);
            }
            right++;
        }
        return max_len;
    }
}
Time Complexity: O(n)

Space Complexity: O(1)
