class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char>st;
        string res="";
        for(int i=0;i<s.size();i++)
        {
            while(!st.empty() && k>0 && st.top()-'0'>s[i]-'0')
            {
                st.pop();
                k--;
            }
            st.push(s[i]);

        }
        
       while(!st.empty() && k>0)
        {
            st.pop();
            k--;
        }//EDGE CASE-1 IF NUM IS IN ACSENDING ORDER
        if(st.empty()) return "0";//EDGE CASE-2  IF K==N
        //EDGE CASE-3 TRIMMIN LEADING ZEROES
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        while(res.size()!=0 && res.back()=='0')
        {
            res.pop_back();
        }
        if(res.empty()) return "0";

        reverse(res.begin(),res.end());
        return res;
    }
};
TC:O(3N)+O(K)
SC:O(2N)
