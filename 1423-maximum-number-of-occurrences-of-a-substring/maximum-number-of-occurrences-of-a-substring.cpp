class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        // Logic: If a substring of maxsize occurs X times, it's prefix of length minsize must also occur X times, hence we only need to check minsize
        // While this is a rolling hash problem, we can use standard hashmap wiith a set to count maxletters in O(n*minsize) time
        unordered_map<string, int> counts;
        int maxOccurences=0;

        for(int i=0; i<=s.size()-minSize; i++){
            string sub= s.substr(i, minSize);
            unordered_set<char> unique(sub.begin(), sub.end());
            if(unique.size()<=maxLetters){
                counts[sub]++;
                maxOccurences= max(maxOccurences, counts[sub]);
            }
        }
        return maxOccurences;
    }
};