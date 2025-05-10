class Solution {
public:
    int jump(vector<int>& nums) {
         int f=0;
       long long int l=0;
       long long  int r=0;
        int j=0;
        while(r<nums.size()-1)
        {
            for(int i=l;i<=r;i++)
            {
                f=max(i+nums[i],f);

            }
            l=r+1;
            r=f;
            j++;
        }
        return j;
    }
};
