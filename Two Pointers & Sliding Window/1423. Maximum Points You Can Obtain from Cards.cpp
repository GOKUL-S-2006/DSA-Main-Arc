class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int lsum=0;
        int rsum=0;
        for(int i=0;i<k;i++)
        {
         lsum+=nums[i];
        }
        int maxsum=lsum;
        int ri=nums.size()-1;
        for(int i=k-1;i>=0;i--)
        {
            lsum=lsum-nums[i];
            rsum+=nums[ri];
            ri--;
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};
TC:O(2K);
SC:O(1)
Idea:
Caluclate left sum and right sum and find the maxsum




class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        // Step 1: find total sum of all cards
        int totalSum = 0;
        for (int x : cardPoints)
            totalSum += x;

        // If we take all cards
        if (k == n)
            return totalSum;

        // Step 2: size of cards NOT taken
        int windowSize = n - k;

        int currSum = 0;
        int minSum = INT_MAX;

        // Step 3: sliding window to find minimum sum of (n-k) cards
        for (int i = 0; i < n; i++) {
            currSum += cardPoints[i];     // add current element

            // if window size exceeded, remove left element
            if (i >= windowSize)
                currSum -= cardPoints[i - windowSize];

            // when window size is exactly (n-k), update min
            if (i >= windowSize - 1)
                minSum = min(minSum, currSum);
        }

        // Step 4: maximum score
        return totalSum - minSum;
    }
};


Time Complexity  : O(n)
Space Complexity : O(1)



    
