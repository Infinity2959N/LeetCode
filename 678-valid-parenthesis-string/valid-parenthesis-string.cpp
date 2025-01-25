class Solution {
public:
    bool checkValidString(string s) {   //using greedy
        int low=0,high=0;
        /*
        if (, increase both;
        if ), decrese both;
        if *, decrease low, increase high.

        if high becomes -1 at an point, return false, if low becomes -1, reset
        in the end, if low=0, return true.
        */
        for(char c: s){
            if(c=='('){
                low++;
                high++;
            }else if(c==')'){
                low--;
                high--;
            }else{
                low--;
                high++;
            }
            if(high<0)   return false;
            if(low<0)   low=0;
        }
        return low==0;
    }    
};