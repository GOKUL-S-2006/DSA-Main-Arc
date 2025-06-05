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


Optimal solution:

 //using for loop mark index of each char 
 //after marking we are assuming that each index is last valid index to check valid substring every index of a,b,c should not be -1;
 //If so then find the minindexof min(a,b,c) where the valid abc window is started if you add 1+min(a,b,c) then you will get the all number of valid substring till that index
int numberOfSubstrings(string s) {

       int n=s.size();

       vector<int> lastseen(3,-1);

       int numofsubstr=0;

       for(int i=0;i<n;i++){

            lastseen[s[i]-'a']=i;

            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){

              numofsubstr+=1+min({lastseen[0],lastseen[1],lastseen[2]});
                
            }
       }

       return numofsubstr;
 }

TC->O(N)
SC->O(3)
