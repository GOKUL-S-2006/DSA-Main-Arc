class Solution {
public:
   //it is similar to leetcode 402 : remove k digits. just like choose k digit and remove (len(nums)-k) digit to make the concatenate of the subarray smallest. this is my explanation for that problem:https://leetcode.com/problems/remove-k-digits/solutions/3797104/explanation-for-beginners-like-me/
    
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        
        int n=nums.size();

        int temp=n-k;

        stack<int> st;

        for(int i=0;i<n;i++){

            while(!st.empty() && temp>0 && st.top()>nums[i]){
                temp--;
                st.pop();
            }
            st.push(nums[i]);
        }

         vector<int> rem,ans;

         while(!st.empty()){
            rem.push_back(st.top());
            st.pop();
         }

         int n1=rem.size();

         for(int  i=n1-1;i>=n1-k;i--){
            ans.push_back(rem[i]);
            
         }

         return ans;
    }
};
