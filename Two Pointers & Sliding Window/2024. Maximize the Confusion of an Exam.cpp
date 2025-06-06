IDEA:
EXACT QUESTION AS LONGEST CHARACTER AFTER REPLACEMENT
JUST USE SLIDING WINDOW AND MAXIMIZE THE EXAM.
code:
class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        vector<int> hash(2);  // index 0: 'F', index 1: 'T'
        int l = 0, r = 0;
        int n = s.size();
        int maxlen = 0, maxf = 0;

        while (r < n) {
            hash[s[r] == 'T']++;
            maxf = max(hash[0], hash[1]);

            while ((r - l + 1) - maxf > k) {
                hash[s[l] == 'T']--;
                maxf = max(hash[0], hash[1]);  // recompute after shrinking
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;
    }
};

Time Complexity	:O(n)
Space Complexity:	O(1) (vector of size 2)
