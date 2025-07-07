class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int>ans;
        int n=heights.size();
        int maxv=n-1;
        ans.push_back(maxv);
        for(int i=n-1;i>=0;i--){
            if(heights[i]>heights[maxv]){
                ans.push_back(i);
                maxv=i;

            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;



    }
};
