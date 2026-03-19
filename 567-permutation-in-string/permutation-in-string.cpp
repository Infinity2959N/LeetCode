class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;

        vector<int> s1Map(26, 0), s2Map(26, 0);
        
        // Build initial maps for the first 'n1' characters
        for (int i = 0; i < n1; i++) {
            s1Map[s1[i] - 'a']++;
            s2Map[s2[i] - 'a']++;
        }

        // Check if the very first window is a match
        if (s1Map == s2Map) return true;

        // Slide the window across s2
        for (int i = n1; i < n2; i++) {
            // Add the new character on the right
            s2Map[s2[i] - 'a']++;
            // Remove the old character on the left (i - n1)
            s2Map[s2[i - n1] - 'a']--;

            // Vector comparison in C++ is O(26), which is effectively O(1)
            if (s1Map == s2Map) return true;
        }

        return false;
    }
};