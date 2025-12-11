Brute Force Solution (O(n²) time, O(1) space)

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(nums[j] == nums[i]) count++;
        }
        if(count > n/2) return nums[i];
    }
    return -1;
}



Better Solution

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> mp;
    int n = nums.size();

    for(int x : nums) {
        mp[x]++;
        if(mp[x] > n/2) return x;
    }
    return -1;
}


Only one pass → O(n)

But uses extra space O(n)

int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;

    for(int num : nums) {
        if(count == 0)
            candidate = num;

        if(num == candidate)
            count++;
        else
            count--;
    }
    return candidate;
}


TC:O(N)
SC:O(1)





