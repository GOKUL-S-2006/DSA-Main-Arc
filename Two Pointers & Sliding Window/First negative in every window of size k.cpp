class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
       int n = arr.size();
        int l = 0, r = 0;
        vector<int> ans;
        deque<int> dq; // store indices of negative numbers

        while (r < n) {
            // if current element is negative, add index
            if (arr[r] < 0) {
                dq.push_back(r);
            }

            // when window size is exactly k
            if (r - l + 1 == k) {
                if (dq.empty()) {
                    ans.push_back(0);
                } else {
                    ans.push_back(arr[dq.front()]); // first negative element
                    // if this element is going out of window, remove it
                    if (dq.front() == l) {
                        dq.pop_front();
                    }
                }
                l++; // shrink window
            }
            r++;
        }
        return ans;
        
    }
};
