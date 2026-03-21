class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        //Basics of GCD:
        // Bezout's identity: 
        // For any integers a and b, the smallest positive integer that can be written in the form of ax+ by is exactly GCD(a, b).

        // Extension: Any number that can be formed by adding or subtracting multiples of a and b must be a multiple of GCD(a, b).

        // Approach for the question: Find frequency of all, and then GCD of frequencies. If greater than 2, there is a common partition size that works for all

        unordered_map<int, int> cards;
        for(int val: deck){
            cards[val]++;
        }
        int curr= 0;
        for(const auto& pair: cards){
            curr= gcd(curr, pair.second);
            if(curr==1) return false;
        }

        return curr>=2;
    }
};