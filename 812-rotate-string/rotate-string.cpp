class Solution {
public:
    bool rotateString(string s, string goal) {
        // Trick: Concatenate the source with itself. Any combination of rotated string will be found there.
        if(s.size()!= goal.size())  return false;
        return (s+s).find(goal) != string:: npos;
    }
};