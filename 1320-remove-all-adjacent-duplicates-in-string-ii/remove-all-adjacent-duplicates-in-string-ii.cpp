class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(char c: s){
            if(!st.empty() && c==st.top().first){
                st.top().second++;
                if(st.top().second==k){
                    st.pop();
                }
            }
            else{
                st.push({c,1});
            }
        }

        string result="";
        while(!st.empty()){
            char ch=st.top().first;
            int count=st.top().second;
            st.pop();

            result= string(count,ch)+result;    //add character count times
        }
        return result;
    }
};