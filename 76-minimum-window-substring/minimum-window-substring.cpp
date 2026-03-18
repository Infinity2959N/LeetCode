class Solution {
public:
    string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";

    int target[128] = {0};
    for (char c : t) target[c]++;

    int requiredUnique = 0;
    for (int i = 0; i < 128; i++) {
        if (target[i] > 0) requiredUnique++;
    }

    int window[128] = {0};
    int formed = 0;
    int left = 0, minLen = INT_MAX, startIdx = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        window[c]++;

        // ADD: Check if we just satisfied a character's requirement
        if (target[c] > 0 && window[c] == target[c]) {
            formed++;
        }

        // SHRINK: While the window is valid, try to make it smaller
        while (formed == requiredUnique) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                startIdx = left;
            }

            char leftChar = s[left];
            // If removing this char breaks the "valid" state
            if (target[leftChar] > 0 && window[leftChar] == target[leftChar]) {
                formed--;
            }
            window[leftChar]--;
            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
}
};