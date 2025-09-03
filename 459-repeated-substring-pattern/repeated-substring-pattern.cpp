class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // String concatenation trick:
        string newStr= s+s;
        string sub= newStr.substr(1, newStr.size()-2);
        return sub.find(s)!= string::npos;
    }
};