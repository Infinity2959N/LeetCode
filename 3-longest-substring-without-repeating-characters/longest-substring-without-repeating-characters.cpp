class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> lookup;
        int maxSize = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            // Shrink phase: If s[right] is a duplicate, shrink until it's not
            while (lookup.count(s[right])) {
                lookup.erase(s[left]);
                left++;
            }
            
            // Expand phase: Now it's safe to add s[right]
            lookup.insert(s[right]);
            
            // Result update: Window size is always right - left + 1
            maxSize = max(maxSize, right - left + 1);
        }
        return maxSize;
    }
};