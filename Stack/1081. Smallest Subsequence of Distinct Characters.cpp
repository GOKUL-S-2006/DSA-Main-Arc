class Solution {
public:
    string smallestSubsequence(string s) {
        map<char,pair<int,bool>>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]={i,false};
        }
        stack<char>st;
        for(int i=0;i<s.size();i++){
            int c=s[i];
            if(mpp[c].second==true){
                continue;
            }
            while(!st.empty() && st.top()>c && i<mpp[st.top()].first){
                mpp[st.top()].second=false;
                st.pop();
            }
            st.push(c);
            mpp[c].second=true;
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
