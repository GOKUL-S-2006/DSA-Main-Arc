Problem

Count subarrays whose sum is a perfect square.

Perfect squares:

0, 1, 4, 9, 16 ...


Code:
int perfectSubarrays(vector<int>& nums) {
    
    unordered_map<int,int> mp;
    mp[0] = 1;
    
    int prefix = 0;
    int ans = 0;

    for(int x : nums)
    {
        prefix += x;

        for(int k = 0; k*k <= prefix; k++)
        {
            int square = k*k;

            if(mp.count(prefix - square))
            {
                ans += mp[prefix - square];
            }
        }

        mp[prefix]++;
    }

    return ans;
}

Complexity

Time:

O(N √MAX_SUM)

Space:

O(N)


Key Formula

sum(i..j) = prefix[j] - prefix[i-1]

Core Intuition

If a subarray sum is a perfect square:

prefix[j] - prefix[i-1] = k²

Rearrange:

prefix[i-1] = prefix[j] - k²

Meaning:

If current prefix − perfect square existed before,
then the subarray sum is a perfect square.

Approach (Short)

Maintain prefix sum.

Store previous prefixes in a hashmap.

For each prefix:

try perfect squares k*k

check if (prefix - k*k) exists in map.

If yes → add its frequency to answer.

Store current prefix in map.
