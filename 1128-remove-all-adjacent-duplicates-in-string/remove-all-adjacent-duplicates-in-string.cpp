class Solution {
public:
    string removeDuplicates(string S) {

        string res = "";    //using res as a stack
        for (const char& c : S)
            if (res.size() && c == res.back())
                res.pop_back();
            else
                res.push_back(c);
        return res;

    }
};