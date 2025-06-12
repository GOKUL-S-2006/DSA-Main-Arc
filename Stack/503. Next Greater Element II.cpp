class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n * 2; ++j) { // j = 1 to 2n - 1
                int nextIndex = (i + j) % n;
                if (nums[nextIndex] > nums[i]) {
                    res[i] = nums[nextIndex];
                    break;
                }
            }
        }

        return res;
    }
};
TC;O(N^2)
SC:O(N)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--) O(2N)
        {
            while(!st.empty() && st.top()<=arr[i%n] )
            {
               st.pop();O(2N)
            }
            if(i<n)
            {
                ans[i]=st.empty()?-1:st.top();
            }
            st.push(arr[i%n]);
        }
        return ans;
    }
};
TC;O(4N)
SC:O(2N)
