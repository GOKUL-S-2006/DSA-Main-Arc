

//Think the problem like you can have at max 2 distint element in an subarray if it goes beyound that then shrink from back
//we are make suring that 2 distinct element by using mpp and mpp.size<=2

Optimal code:

int totalFruit(vector<int>& fruits) {
            
        map<int,int> mpp;
        
        int n=fruits.size();

        int l=0,r=0,maxlen=0;

        while(r<n){

            mpp[fruits[r]]++;

            //It it voilates the condition then i will not allow the window to grow
            if(mpp.size()>2){
                  mpp[fruits[l]]--;
                  if (mpp[fruits[l]] == 0) mpp.erase(fruits[l]);  
                  l++;
            }
             
            if(mpp.size()<=2)maxlen=max(maxlen,r-l+1);
            r++;
        }

        return maxlen;

    }

TC->O(N)
SC->O(N)  
