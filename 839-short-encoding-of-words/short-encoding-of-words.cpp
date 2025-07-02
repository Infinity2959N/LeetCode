class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());

        for (const string& word : words) {
            for (int i = 1; i < word.size(); ++i) {
                s.erase(word.substr(i));
            }
        }

        int totalLength = 0;
        for (const string& word : s) {
            totalLength += word.size() + 1; // +1 for the '#'
        }
        return totalLength;
    }
};
