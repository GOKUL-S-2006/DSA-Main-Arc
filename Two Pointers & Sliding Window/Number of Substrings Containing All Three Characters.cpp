BRUTE FORCE:
GENERATE ALL SUBSTRINGS AND FIND.


BETTER:
USING SLIDING WINDOW 
class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0;
        int c=0;
        int n=s.size();
        map<char,int>mpp;
        while(r<s.size())
        {
           mpp[s[r]]++;
           while(mpp.size()==3)
           {
              c+=n-r;
              mpp[s[l]]--;
              if(mpp[s[l]]==0)
              {
                mpp.erase(s[l]);
              }
              l++;
           }
           r++;
              
           }
           return c;
        }
    
};
