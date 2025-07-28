class Solution {
public:
    bool canAssign(vector<int>&nums,int val,int op){
       long long c = 0;
        for(int i=0;i<nums.size();i++){
            //c+=ceil((double)nums[i]-val/val);
            c += ceil((double)nums[i] / val) - 1;

        }
        return c<=op;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int res=INT_MAX;
        while(low<=high){
           int mid=low+(high-low)/2;
            if(canAssign(nums,mid,maxOperations)){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};


TC:O(N Log(R)) R=>Max Element
SC:O(1)
