class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        map<int,int>mpp;
        mpp[0]=-1;
       long long  int sum=0;
        for(int n:nums){
            sum+=n;
        }
        if(sum%p==0){
            return 0;
        }
        int rem=sum%p;
        int minl=INT_MAX;
        long long int pre=0;
        for(int i=0;i<nums.size();i++){
            pre=(pre+nums[i])%p;
            int target=(pre-rem+p)%p;
            if(mpp.find(target)!=mpp.end()){
                minl=min(minl,i-mpp[target]);
            }
            mpp[pre]=i;
        }
        return (minl == nums.size() || minl == INT_MAX) ? -1 : minl;
    }
};



Time: O(n)
Space: O(n)




Approach — Make Sum Divisible by P
1️⃣ Compute total sum

First compute the total sum of the array.

total = sum(nums)
rem = total % p

If rem == 0, the array sum is already divisible by p, so we return 0 because no removal is needed.

2️⃣ Key Observation

If the total sum is not divisible by p, then

total = k*p + rem

To make the remaining sum divisible by p, we must remove a subarray whose sum has remainder rem.

(total - subarray) % p = 0

Thus,

subarray % p = rem

So the task reduces to:

Find the smallest subarray whose sum modulo p equals rem.

3️⃣ Use Prefix Sum + Hash Map

Let

prefix[i] = sum of elements from 0 to i

The sum of a subarray (i+1 … j) is

subarray = prefix[j] - prefix[i]

We need

(prefix[j] - prefix[i]) % p = rem

Rearranging,

prefix[i] % p = (prefix[j] - rem + p) % p

This means:

For every prefix remainder, we check if a previous prefix with remainder
(prefix - rem + p) % p exists.

4️⃣ Algorithm

Compute rem = total % p.

Use a hashmap to store prefix remainder → index.

Initialize map[0] = -1 to handle subarrays starting at index 0.

Traverse the array:

Update prefix = (prefix + nums[i]) % p

Compute

need = (prefix - rem + p) % p

If need exists in the map, update the minimum subarray length.

Store the current remainder and index in the map.

5️⃣ Edge Case

If the minimum length equals the array length, it means we would have to remove the entire array, which is not allowed. Return -1.

6️⃣ Complexity

Time Complexity

O(n)

Space Complexity

O(n)

✅ Core Idea (1-line summary for revision)

Find the smallest subarray whose sum % p = totalSum % p using prefix sums and a hashmap.
