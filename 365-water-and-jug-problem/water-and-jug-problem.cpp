class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        // Additions and subtractions-> GCD
        // Approach: any total amount of water we can measure should be a multiple of gcd(x, y) (Bezout's theorem)
        // Obviously can't measure more than total capacity: x+y
        // Strategy: return true if target<=x+y & target% gcd==0
        return (target<=x+y && target% gcd(x,y)==0);
    }
};