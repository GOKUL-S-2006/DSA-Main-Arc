class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        map<int,int>mpp;
        mpp[0]=1;
        int pre=0;
        long long count=0;
        for(int i=0;i<arr.size();i++){
            pre^=arr[i];
            count+=mpp[pre^k];
            mpp[pre]++;
        }
        return count;
    }
};
