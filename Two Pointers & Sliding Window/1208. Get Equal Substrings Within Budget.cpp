Brute Force

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxlen=0;
        int l=0,r=0;
        int temp=maxCost;
        while(r<s.size())
        {
            if(abs(s[r]-t[r])<=temp)
            {
                temp-=abs(s[r]-t[r]);
                maxlen=max(maxlen,r-l+1);
                r++;
                
            }
            else
            {
                l++;
                r=l;
                temp=maxCost;


            }
        }
       return maxlen;
    }
};

IDEA:
Just maintain two pointer l and r ..if the cost is still less than maxcost increase r pointer 
if cost exceeds maxcost increase the l pointer and after set the r pointer equal = l;
then change the cost to its intitilal value maxcost;
TC:O(N^2)
SC:O(1)



Optimized

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int l=0;
        int r=0;
        int maxlen=0;
        int cost=0;
        int n=s.size();
        while(r<n)
        {
            cost+=abs(s[r]-t[r]);
            if(cost>maxCost)
            {
                while(cost>maxCost)
                {
                    cost-=abs(s[l]-t[l]);
                    l++;
                }
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        
        return maxlen;
    }
};

IDEA:
KEY -THIS IS EXACT AS SAME FIND THE LENGTH OF LARGEST SUBARRAY WITH SUM <=K 
  Same logic here ->->just add the cost ..if it exceeds then increase l pointer and update the maxlen and r pointer

TC:O(N)
SC:O(1)

  
