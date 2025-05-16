class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0)
            return false;

        map<int, int> count;
        for (int card : nums) {
            count[card]++;
        }

        for (auto x : count) {
            int start = x.first;
            int value = count[start];
            if (value > 0) {
                for (int i = start; i < start + k; ++i) {
                    count[i] -= value;
                    if (count[i] < 0)
                        return false;
                }
            }
        }

        return true;
    }
};
