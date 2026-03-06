class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int oc=0;
        int ec=1;
       long long  int c=0;
       int mod = 1e9 + 7;
        int pre=0;
        for(int i=0;i<arr.size();i++){
              pre += arr[i];

            if(pre & 1){
                c = (c + ec) % mod;
                oc++;
            }
            else{
                c = (c + oc) % mod;
                ec++;
            }
        }
         
        return c;
    }
};
