class Solution {
public:
    int ans=0;
    void pick(string &s,int cnt,char c){
        for(int i=0;i<cnt;i++){
            s+=string(1,c);
        }
        
    }
    void not_pick(string &s,int cnt){
         for (int i = 0; i < cnt && !s.empty(); i++) { 
            s.pop_back();
        }
    }
    void helper(string &s,int &low,int &high,int &zc,int &oc){
        if(s.size()>high){
            return;
        }
        if(s.size()>=low && s.size()<=high){
            ans++;
        }
        
        pick(s,zc,'0');
        helper(s,low,high,zc,oc);
        not_pick(s,zc);
        pick(s,oc,'1');
        helper(s,low,high,zc,oc);
        not_pick(s,oc);


    }
    int countGoodStrings(int low, int high, int zero, int one) {
        string s="";
        helper(s,low,high,zero,one);
        return ans;
    }
};


Final Answer
Time Complexity: O(2^(high / min(zero, one))) → ❌ exponential
Space Complexity: O(high) → ✔️ linear




