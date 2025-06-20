class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push((long long)nums[i]);
        }

        int op = 0;

        while (pq.size() >= 2 && pq.top() < k) {
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            long long val = x * 2 + y;
            pq.push(val);
            op++;
        }

        if (pq.top() < k) return -1; // if even after all operations, value < k

        return op;
    }
};
