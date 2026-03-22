class Solution {
public:
    int numDecodings(string s) {
        // two questions for each index:
        // A. Can I take it alone; if yes: dp[i]+= dp[i-1] (Edge case: 0 can't come)
        // B. Can I make a pair with previous: dp[i]+= dp[i-2]  (should be between 10-26)
        // Edge cases with 0s: If we have a leading 0, or a 0 after any digit that's not 1 or 2, there will be no valid decodes
        int n= s.size();
        if(s[0]=='0' || n==0) return 0;

        vector<int> dp(n+1, 0);
        dp[0]= 1;   // base case: empty string: Safety net for dp[i-2]
        dp[1]= 1;   // Base case: First element (which is verified non zero)
        
        for(int i=2; i<= n; i++){
            // Case 1: standalone
            if(s[i-1]!='0') dp[i]+=dp[i-1];

            // Case 2: pair
            int twodigit= stoi(s.substr(i-2, 2));
            if(twodigit>=10 && twodigit<=26)   dp[i]+=dp[i-2];

        }
        return dp[n];
    }
};