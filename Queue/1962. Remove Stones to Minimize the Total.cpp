class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
       // priority_queue<int, vector<int>, greater<int>> pq;
       priority_queue<int>pq;
        for(int i=0;i<piles.size();i++)
        {
            pq.push(piles[i]);
        }
        int score=0;
        while(k)
        {
            int num=pq.top()-pq.top()/2;
            pq.pop();
            pq.push(num);
            k--;

        }
        while(!pq.empty())
        {
            score+=pq.top();
            pq.pop();
        }
        return score;

    }
};
