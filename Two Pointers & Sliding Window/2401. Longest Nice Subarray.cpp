class Solution {
public:
    int longestNiceSubarray(vector<int>& arr) {
        int maxlen=1;
       
        int l=0;
        int r=0;
        int cursum=0;
        int xorv=0;
        int n=arr.size();
        while(r<n)
        {
            cursum+=arr[r];
            xorv^=arr[r];
            if(cursum==xorv)
            {
                maxlen=max(maxlen,r-l+1);
                r++;

            }
            else
            {
                l++;
                r=l;
                cursum=0;
                xorv=0;
            }
           
            

        }
        return maxlen;
    }
};

IDEA:
Maintain two variables current sum and current xor ->for some reasons (Bitwise property) the sum of elements and the xor of the elmenets shld be same..
if it is same calculate the maxlen and increase r++;
else
increase the l pointer and set r=l;

TC:O(N)
SC:O(1);
CLEANER CODE
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
         int n=nums.size();
        int left=0;
        int right=0;

        //2-Pointer: Variable size sliding window
        int max_window_size = 0;
        int xor_sum=0;
        int curr_sum=0;
        while(right<n){
            curr_sum += nums[right];
            xor_sum ^= nums[right];
            while(xor_sum!=curr_sum){
                curr_sum -= nums[left];
                xor_sum ^= nums[left];
                left++;
            }
            max_window_size = max(max_window_size,right-left+1);
            right++;
        }
        return max_window_size;
    }
};
