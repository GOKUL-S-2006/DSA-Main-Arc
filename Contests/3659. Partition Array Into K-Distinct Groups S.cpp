class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
      int n=nums.size();
      //If total elemenst are not divisble by k,partioioing is impossibe
      if(n%k!=0){
        return false;
      }
      int totalGroups=n/k;
      map<int,int>mpp;
      for(auto x:nums){
        mpp[x]++;
      }
      //If any frequency is greater than total Grops its impossible to divide
      for(auto x:mpp){
        if(x.second>totalGroups){
            return false;
        }
      }
      return true;
    }
    
};
