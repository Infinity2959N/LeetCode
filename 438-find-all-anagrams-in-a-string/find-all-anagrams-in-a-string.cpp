class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n = s.size(), m = p.size();
        if (m > n) return res;

        vector<int> pFreq(26, 0), sFreq(26, 0);
        for (char c : p) pFreq[c - 'a']++;

        for (int i = 0; i < n; i++) {
            // 1. Add the current character (right side of window)
            sFreq[s[i] - 'a']++;

            // 2. If window size exceeds m, remove the leftmost character
            if (i >= m) {
                sFreq[s[i - m] - 'a']--;
            }

            // 3. Compare frequencies (Only when window is exactly size m)
            if (i >= m - 1) {
                if (pFreq == sFreq) res.push_back(i - m + 1);
            }
        }
        return res;
    }
};