Referernce from :930. Binary Subarrays With Sum ->**See this problem first similar**


Brute Force:(TC->O(N2),SC->O(1))
     ->Generate All possiible subarray and cnt and return answer

Better solution:
      ->Using hashMap

Optimal solition:
    
     int countsubarrylessthanorequalk(vector<int>& arr,int k){

        int n=arr.size();

        int cnt=0,l=0,r=0,oddcnt=0;

        while(r<n){
              if(arr[r]%2!=0)oddcnt++;

              while(oddcnt>k){
                if(arr[l]%2!=0)oddcnt--;
                l++;
              }

              cnt+=r-l+1;
              r++;
        }
      return cnt;
    } 
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countsubarrylessthanorequalk(nums,k)-countsubarrylessthanorequalk(nums,k-1);
        
    }

TC->O(2N)
SC->O(N)
