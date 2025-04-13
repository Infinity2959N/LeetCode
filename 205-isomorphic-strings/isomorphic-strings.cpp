class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!= t.size()) return false;
        unordered_map<char, char> charMap1, charMap2;
        int n= s.size();
        for(int i=0; i<n; i++){
            int c1= s[i], c2= t[i];
            if(charMap1.count(c1)==0)  charMap1[c1]=c2;
            else{
                if(charMap1[c1]!=c2) return false;
            }
            if(charMap2.count(c2)==0)  charMap2[c2]=c1;
            else{
                if(charMap2[c2]!=c1) return false;
            } 
        }
        return true;
    }
};