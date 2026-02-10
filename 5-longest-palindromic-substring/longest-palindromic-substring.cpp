class Solution {
public:
    string longestPalindrome(string s) {
        // Approach: O(n^2): Go for each element, and start expanding left and right till it is a palindrome. If the size is greater than previously stored palindrome, replace.
        // Apparently the question breaks constraints, so size may also be 0
        if(s.size()<2)   return s;

        string ans=s.substr(0,1);    //single char is always palindrome
        int l, r;
        for(int i=0; i<s.size(); i++){
            // Odd length
            l=i, r=i;
            
            while(l>-1 && r<s.size() && s[l]==s[r]){
                l--;
                r++;
            }
            if(r-l-1> ans.size()){
                ans= s.substr(l+1, r-l-1);
            }

            // Even length (For each i, can have both odd and even length palindromes)
            l=i, r=i+1;
            
            while(l>-1 && r<s.size() && s[l]==s[r]){
                l--;
                r++;
            }
            if(r-l-1> ans.size()){
                ans= s.substr(l+1, r-l-1);
            }
        }
        return ans;
    }
};