class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tanks=0;
        int shortage=0;
        int start=0;
        for(int i=0;i<gas.size();i++)
        {
            tanks+=gas[i];
            if(tanks>=cost[i])
            {
                tanks-=cost[i];
            }
            else
            {
                shortage+=cost[i]-tanks;
                start=i+1;
                tanks=0;
            }
        }
        if(start==gas.size() || tanks<shortage)
        {
            return -1;
        }
        return start;
    }
};
