class Solution {
public:
   //ideas:
   //If there is no zero we can always reach the end 
   //standing at each index and checking that did i was touched by someone previously 
    bool canJump(vector<int>& nums) {
        
        
        int n=nums.size();

        int maxind=0;

        for(int i=0;i<n;i++){

            //if i was not touched by previous one return false
            if(i>maxind)return false;
            //little optimisation that if someone can reach the last index ther no use of checking after 
            if(maxind==n-1)break;
            
            maxind=max(maxind,i+nums[i]);
        }

        return true;


    }
};

TC->O(N)
SC->O(1)
