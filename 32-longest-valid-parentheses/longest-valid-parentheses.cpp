class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()<2) return 0;
        int currMax= 0;
        vector<int> dp(s.size(), 0);

        for(int i=1; i<s.size(); i++){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i]= (i-2)>=0? dp[i-2]+2: 2;
                    currMax= max(currMax, dp[i]);
                }
                else{   // s[i-1]==')': combine the previouslength
                    int j= i-dp[i-1]-1; // Character right before the valid segment of previous ')'
                    if(j>-1 && s[j]=='('){
                        dp[i]= dp[i-1]+ 2+ ((j-1>=0)? dp[j-1]:0);
                        currMax= max(currMax, dp[i]);
                    }
                }
            }
        }
        return currMax;
    }
};