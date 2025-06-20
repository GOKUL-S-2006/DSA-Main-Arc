class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score=0;
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);

        }
        while(k)
        {

            score+=pq.top();
            int num=(pq.top()+2)/3;
            pq.push(num);
            pq.pop();
            k--;
        }
        return score;

    }
};
