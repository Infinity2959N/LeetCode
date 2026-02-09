class Solution {
public:
    bool isAnagram(string s, string t) {
        // edge case: Different sizes
        if(s.size()!= t.size()) return false;
        
        // Simplest approach: Sort and match
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for(int i=0; i<s.size(); i++){
            if(s[i]!= t[i]) return false;
        }

        return true;
    }
};