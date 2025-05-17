key idea:

     ->sort the meeting based on the end time 
     -> check the new meeting is overlapping with existing meeting with end time of existing meeting and start time of the new meeting





int maxMeetings(vector<int>& start, vector<int>& end) {
       
       
         vector<pair<int,int>> arr;
         int n=start.size();
         
         //storing in backward fasion like {endtime of meeting, starttime of meeting}
         for(int i=0;i<n;i++){
             arr.push_back({end[i],start[i]});
         }
         
         sort(arr.begin(),arr.end());
         
         //Assuming first meeting is going on
         int cnt=1;
         
         int st=arr[0].second,en=arr[0].first;
         
         for(int i=1;i<n;i++){
             
                // comparing as per given condition(The start time of one chosen meeting can't be less than or equal to the end time of the going meeting.) 
                if(arr[i].second>en){
                    cnt++;
                    st=arr[i].second;
                    en=arr[i].first;
                }
         }
         return cnt;
         
    }
