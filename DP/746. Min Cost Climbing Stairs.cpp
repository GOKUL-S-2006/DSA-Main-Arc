Recursion:

class Solution {
public:
   int helper(int n,vector<int>&cost){
     if(n==0){
        return cost[0];
     }
     if(n==1){
        return cost[1];
     }
    
     int cost2=INT_MAX;
     int cost1=cost[n]+helper(n-1,cost);
     if(n>1){
        cost2=cost[n]+helper(n-2,cost);
     }
     return min(cost1,cost2);
   }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int ans=min(helper(n-1,cost),helper(n-2,cost));
        return ans;
    }
};

Time complexity = O(2ⁿ)

Memoization:

class Solution {
public:
   int helper(int n,vector<int>&cost,vector<int>&dp){
     if(n==0){
        return cost[0];
     }
     if(n==1){
        return cost[1];
     }
     if(dp[n]!=-1){
        return dp[n];
     }
    
     int cost2=INT_MAX;
     int cost1=cost[n]+helper(n-1,cost,dp);
     if(n>1){
        cost2=cost[n]+helper(n-2,cost,dp);
     }
     return dp[n]=min(cost1,cost2);
   }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        int ans=min(helper(n-1,cost,dp),helper(n-2,cost,dp));
        return ans;
    }
};

TC:O(n)
SC:O(n)+O(n)(Recursion stack)

Tabulation:

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,0);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=min(cost[i]+dp[i-1],cost[i]+dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};

TC;O(N)
SC:O(N)

Space Optimization:

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        if (n == 2) return min(cost[0], cost[1]);

        int prev2 = cost[0];
        int prev1 = cost[1];

        for (int i = 2; i < n; i++) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};


TC:O(N)
SC:O(1)



