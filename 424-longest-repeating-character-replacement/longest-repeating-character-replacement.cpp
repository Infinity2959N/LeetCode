class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, maxFreq = 0, maxLength = 0;
        int counts[26] = {0}; // Frequency map for A-Z

        for (int right = 0; right < s.size(); right++) {
            // 1. ADD: Update frequency of the new character
            counts[s[right] - 'A']++;
            
            // 2. UPDATE KING: Is this new character now the most frequent?
            maxFreq = max(maxFreq, counts[s[right] - 'A']);

            // 3. SHRINK: If (Total Size - King Count) > Budget, window is invalid
            while ((right - left + 1) - maxFreq > k) {
                counts[s[left] - 'A']--;
                left++;
                // Note: We don't actually need to update maxFreq here. 
                // A smaller maxFreq won't give us a better maxLength anyway.
            }

            // 4. MEASURE: Window is guaranteed valid now
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};