If you take a closer look at this problem, this is mainly an extension of Longest Subarray with 0 sum.

The idea is based on the fact that if Sj - Si = k (where Si and Sj are prefix sums till index i and j respectively, and i < j), then the subarray between i+1 to j has sum equal to k.
For example, arr[] = [5, 2, -3, 4, 7] and k = 3. The value of S3 - S0= 3, it means the subarray from index 1 to 3 has sum equals to 3.

So we mainly compute prefix sums in the array and store these prefix sums in a hash table. And check if current prefix sum - k is already present. If current prefix sum - k is present in the hash table and is mapped to index j, then subarray from j to current index has sum equal to k.

Below are the main points to consider in your implementation.

If we have the whole prefix having sum equal to k, we should prefer it as it would be the longest possible till that point.
If there are multiple occurrences of a prefixSum, we must store index of the earliest occurrence of prefixSum because we need to find the longest subarray.

// C++ program to find longest sub-array having sum k
// using Hash Map and Prefix Sum

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


// Function to find longest sub-array having sum k
int longestSubarray(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    int res = 0;
    int prefSum = 0;

    for (int i = 0; i < arr.size(); ++i) {
        prefSum += arr[i];

        // Check if the entire prefix sums to k
        if (prefSum == k) 
            res = i + 1;

        // If prefixSum - k exists in the map then there exist such 
      	// subarray from (index of previous prefix + 1) to i.
        else if (mp.find(prefSum - k) != mp.end()) 
            res = max(res, i - mp[prefSum - k]);

        // Store only first occurrence index of prefSum
      	if (mp.find(prefSum) == mp.end())
            mp[prefSum] = i;
    }

    return res;
}

TC->O(N)
SC->O(N) because of hash

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;
    cout << longestSubarray(arr, k) << endl;
}
