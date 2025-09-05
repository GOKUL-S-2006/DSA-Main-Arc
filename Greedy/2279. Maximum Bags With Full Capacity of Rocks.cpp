class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>arr;
        int c=0;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]-rocks[i]==0){
                c++;
            }
            else{
            arr.push_back(capacity[i]-rocks[i]);
            }
        }
        int cur=additionalRocks;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
           if (cur >= arr[i]) {      
        cur -= arr[i];        
        c++;                  
    } else {
        break;               
    }
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                c++;
            }
        }
     return c;

    }
};


Time: O(n log n) (because of sort)

Space: O(n)


