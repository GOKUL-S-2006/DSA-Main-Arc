class Solution {
public:
   int findsum(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n=n/10;
    }
    return sum;
   }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>v=nums;
        sort(v.begin(),v.end(),[&](int a,int b){
            int sumA=findsum(a);
            int sumB=findsum(b);
            if(sumA==sumB) return a<b;
            return sumA<sumB;
        });
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]=i;
        }
        vector<bool>visited(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(visited[i] || v[i]==nums[i]) continue;
            int cycle_size=0;
            int j=i;
            while(!visited[j]){
                visited[j]=true;
                j=mpp[v[j]];
                cycle_size++;
            }
            if(cycle_size>1)
            {
                cnt+=(cycle_size-1);
            }

        }
        return cnt;
    }
};
TC:O(N LOG N)
  
