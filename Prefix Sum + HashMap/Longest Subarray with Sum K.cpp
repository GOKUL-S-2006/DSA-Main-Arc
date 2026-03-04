class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        map<int,int> mpp;
        int pre = 0;
        mpp[0] = -1;   // important
        int maxlen = 0;

        for(int i = 0; i < arr.size(); i++) {
            pre += arr[i];

            if(mpp.find(pre - k) != mpp.end()) {
                maxlen = max(maxlen, i - mpp[pre - k]);
            }

            // store only first occurrence
            if(mpp.find(pre) == mpp.end()) {
                mpp[pre] = i;
            }
        }

        return maxlen;
    }
};
