class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize)
    {
       if (hand.size() % groupSize != 0)
            return false;

        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        for (auto x : count) {
            int start = x.first;
            int value = count[start];
            if (value > 0) {
                for (int i = start; i < start + groupSize; ++i) {
                    count[i] -= value;
                    if (count[i] < 0)
                        return false;
                }
            }
        }

        return true;

        
    }
};
