BRUTE FORCE

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
       map<int,int>mpp;
       int l=0,r=0;
       int minlen=INT_MAX;
       int n=cards.size();
       while(r<n)
       {
          mpp[cards[r]]++;
          while(mpp[cards[r]]>=2)
          {
            minlen=min(minlen,r-l+1);
            mpp[cards[l]]--;
            l++;
          }
          r++;


       }
       return minlen==INT_MAX?-1:minlen;
           
    }
};


OPTIMZED
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> lastSeen;
        int minLen = INT_MAX;

        for (int i = 0; i < cards.size(); ++i) {
            if (lastSeen.count(cards[i])) {
                minLen = min(minLen, i - lastSeen[cards[i]] + 1);
            }
            lastSeen[cards[i]] = i;
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};




