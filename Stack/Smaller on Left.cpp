class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        // code here
        stack<int>st;
        int n=arr.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && (st.top()>=arr[i] ))
            {
                st.pop();
            }
            if(!st.empty())
            {
            ans[i]=st.top();
            }
            else
            {
                ans[i]=-1;
            }
            st.push(arr[i]);
        }
        return ans;
    }
};
Time Complexity: O(n)

Space Complexity: O(n)
