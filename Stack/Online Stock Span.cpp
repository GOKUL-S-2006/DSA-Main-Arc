Brute force
class StockSpanner {
public:
   vector<int>arr;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;

        for(int i=arr.size()-1;i>=0;i--)
        {
                if(arr[i]<=price)
                {
                    span++;
                }
                else
                {
                    break;
                }

        }
        arr.push_back(price);
        return span;
    }
};
OPTIMIZED
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
class StockSpanner {
public:
   stack<pair<int,int>>st;
   int ind=-1;

    StockSpanner() {
        ind=-1;
    }
    
    int next(int val) {
        ind++;
        while(!st.empty() && st.top().first<=val)
        {
            st.pop();
        }
        int ans=ind-(st.empty()?-1:st.top().second);
        st.push({val,ind});
        return ans;
    }
};
TC:O(2N)
OC:O(N)
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
