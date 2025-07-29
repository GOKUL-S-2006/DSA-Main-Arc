class Solution {
public:
  bool assign(vector<int> quantities,int val,int n){
    int c=0;
    for(int i=0;i< quantities.size();i++){
      c += ceil((double)quantities[i] / val);
    }
    return c<=n;

  }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high=*max_element( quantities.begin(), quantities.end());
        int mid;
        int res=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(assign( quantities,mid,n)){
                high=mid-1;
                res=mid;
            }
            else{
                low=mid+1;
            }
        } 
        return res;
    }
};


Time Complexity: O(k * log M)
M  ==>Max element
Space Complexity: O(1) 
