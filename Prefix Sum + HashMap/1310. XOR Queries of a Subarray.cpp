class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        map<int,int>mpp;
        mpp[-1]=0;
        vector<int>ans;
        int xr=0;
        for(int i=0;i<arr.size();i++){
            xr^=arr[i];
            mpp[i]=xr;
        }
        for(int i=0;i<q.size();i++){
            int val=mpp[q[i][1]]^mpp[q[i][0]-1];
            ans.push_back(val);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();
        vector<int> px(n + 1, 0);

        for(int i = 0; i < n; i++){
            px[i+1] = px[i] ^ arr[i];
        }

        vector<int> ans;

        for(auto &q : queries){
            int l = q[0];
            int r = q[1];

            ans.push_back(px[r+1] ^ px[l]);
        }

        return ans;
    }
};
