class Solution {
public:
    int longestBeautifulSubstring(string word) {
         int n = word.size();
        int count = 1;
        int len = 1;
        int ans = 0;

        for(int i = 1; i < n; i++){

            if(word[i] >= word[i-1]){
                len++;

                if(word[i] > word[i-1])
                    count++;
            }
            else{
                len = 1;
                count = 1;
            }

            if(count == 5)
                ans = max(ans, len);
        }

        return ans;
    }
};
