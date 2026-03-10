class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Match: Diagonal top+1
        // Not match: max(left, top)
        // Memory optimization: two rows: curr and prev. Swap in each iteration
        int m= text1.length(), n= text2.length();
        vector<int> prev(n+1, 0);   // Have a filler as first word with 0 occurence
        vector<int> curr(n+1, 0);
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n;j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j]= prev[j-1]+1;
                }else{
                    curr[j]= max(prev[j], curr[j-1]);
                }
            }
            prev= curr;
            for(int i=0; i<=n; i++) curr[i]=0;
        }
        return  prev[n];
    }
};