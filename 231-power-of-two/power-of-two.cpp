class Solution {
public:
    bool isPowerOfTwo(int n) {
        // A power of 2 has only single 1 in binary representation, 
        //so we will be using Brian Kernighan's Algorithm.
        
        return n> 0 && (n & (n-1))==0;
    }
};