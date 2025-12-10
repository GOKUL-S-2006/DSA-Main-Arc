class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int j = 0; 
        for(int i = 0; i < nums.size(); i++){
            if(j < 2 || nums[i] != nums[j - 2]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};


Time Complexity — O(n)

We are using one loop that iterates through all elements once.

For every element, we only do constant work (simple comparisons & assignment).

So,

Time = O(n)

💾 Space Complexity — O(1)

We do not use any extra arrays, maps, vectors, or recursion.

We only use a few integer variables (i, j) regardless of input size.

So,

Space = O(1) — Constant Space


This meets the question requirement of modifying the array in-place without extra memory.

Final Statement for Interview 🗣

Time Complexity: O(n), because each element is processed once.
Space Complexity: O(1), because we modify the array in-place and use only constant extra variables.

