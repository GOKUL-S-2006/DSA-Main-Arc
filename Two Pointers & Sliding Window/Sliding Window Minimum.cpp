#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int l = 0, r = 0;
    deque<int> minv;
    int x = 0;

    while(r < n){
        // maintain increasing deque
        while(!minv.empty() && arr[minv.back()] >= arr[r])
            minv.pop_back();

        minv.push_back(r);

        // shrink window
        while(r - l + 1 > k){
            if(minv.front() == l)
                minv.pop_front();
            l++;
        }

        // XOR only when window size == k
        if(r - l + 1 == k){
            x ^= arr[minv.front()];
        }

        r++;
    }

    cout << x << endl;
}
| Metric           | Complexity   |
| ---------------- | ------------ |
| Time Complexity  | **O(n)**     |
| Space Complexity | **O(n + k)** |
| Auxiliary Space  | **O(k)**     |
