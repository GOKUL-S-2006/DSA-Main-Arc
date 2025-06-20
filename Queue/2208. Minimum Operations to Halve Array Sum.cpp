class Solution {
public:
    int halveArray(vector<int>& nums) {
        int op = 0;
        priority_queue<double> pq;

        double osum = 0;  // use double to store the total sum

        for (int i = 0; i < nums.size(); i++) {
            pq.push((double)nums[i]);
            osum += nums[i];  // accumulate sum as double
        }

        double target = osum / 2.0;

        double reduced = 0.0;

        while (reduced < target) {
            double largest = pq.top(); pq.pop();
            double half = largest / 2.0;
            reduced += half;
            pq.push(half);
            op++;
        }

        return op;
    }
};
