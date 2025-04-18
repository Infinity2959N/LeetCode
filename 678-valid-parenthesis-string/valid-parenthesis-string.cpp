class Solution {
public:
    bool checkValidString(string s) {
        // Greedy approach: Low: min number of (, high: max num of (. (One set = remove one from both)
        int low=0, high=0;
        for(auto ch: s){
            if(ch=='('){
                low++;
                high++;
            }
            else if(ch==')'){
                low--;
                high--;
            }
            else{
                low--;
                high++;
            }
            if(high < 0)    return false;   //too many ')'
            low= max(0, low);
        }
        return (low== 0 || high == 0);
    }
};