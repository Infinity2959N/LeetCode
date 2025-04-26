class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        int h = haystack.size();
        int n = needle.size();

        for (int i = 0; i <= h - n; ++i) {
            int p1 = 0;
            while (p1 < n && haystack[i + p1] == needle[p1]) {
                ++p1;
            }
            if (p1 == n) return i;
        }

        return -1;
    }
};
