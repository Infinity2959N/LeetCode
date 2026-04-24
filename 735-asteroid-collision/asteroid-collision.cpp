class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // Given asteroids in a row, indices represent relative position
        // Absolute value= size, sign=direction, Each moving at same speed
        // If they meet, either smaller one explodes or both explode

        stack<int> st;    // Store all asteroids going right

        vector<int> result;

        for(int a: asteroids){
            if(a>0) st.push(a);
            else{
                while(!st.empty() && st.top()>0 && st.top()<-a){
                    st.pop();
                }
                if(!st.empty() && st.top()== -a){
                    st.pop();  // equal size
                    a=0;
                }
                if((st.empty() || st.top()<0) && a<0) st.push(a);
            }
        }
        vector<int> res(st.size());
        int i=st.size()-1;
        while(!st.empty()){
            res[i--]= st.top(); st.pop();
        }
        return res;
    }
};