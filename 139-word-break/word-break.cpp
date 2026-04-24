class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1);    // dp[i] is true if substring [0->i-1] can be segmented into dictionary words
        dp[0]= true;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n= s.size();
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                //If s[0...j] is valid AND s[j...i] is a word
                if(dp[j] && dict.count(s.substr(j, i-j))){
                    dp[i]=true; break;
                }
            }
        }
        return dp[n];
    }
};