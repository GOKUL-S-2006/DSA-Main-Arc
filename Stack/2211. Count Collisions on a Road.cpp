class Solution {
public:
    int countCollisions(string s) {
         stack<char> st;
        int col = 0;
        
        for(int i = 0; i < s.size(); i++) {
            char current = s[i];
            
            if(current == 'R') {
                st.push('R');
            }
            else if(current == 'L') {
                if(!st.empty() && st.top() == 'R') {
                    // R-L collision: both cars collide
                    col += 2;
                    st.pop();
                    
                    // All previous R's also collide with the stationary car
                    while(!st.empty() && st.top() == 'R') {
                        col++;
                        st.pop();
                    }
                    st.push('S');
                }
                else if(!st.empty() && st.top() == 'S') {
                    // S-L collision: only L car collides
                    col++;
                }
                // If stack is empty or top is 'L', no collision occurs
                else {
                    st.push('L');
                }
            }
            else { // current == 'S'
                // Handle previous R's colliding with S
                if(!st.empty() && st.top() == 'R') {
                    while(!st.empty() && st.top() == 'R') {
                        col++;
                        st.pop();
                    }
                }
                st.push('S');
            }
        }
        
        return col;
    }
};
