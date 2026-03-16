class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // Step 1: Map to store the modulus of each
        // Step 2: Check the number of elements with mod(k)= x should be equal to mod(k)= k-x
        // Negative Numbers trap: C++ calculates mod for negative numbers incorrectly. -1%5=-1 in c++, while it should be it's positive counerpart, i.e. 4
        // Frequency map: Use array, as remainders are bounded
        vector<int> freq(k, 0);

        for(int x: arr){
            // Modulo "trick" to handle oth negative and positive to give a remainder in [0,k-1]. Learn it at all costs.
            int rem= ((x%k)+k)%k;
            freq[rem]++;
        }

        // Check pairing logic

        // Case 1: If rem is 0, it would pair with another one with rem=0, so frequency should be even
        if(freq[0]%2==1) return false;

        // Case 2: Other pairs. if the mods add up to k, it's a valid pair.
        for(int i=1; i<=(k-1)/2; i++){
            if(freq[i]!= freq[k-i]) return false;
        }

        // Case 3: For even k, The middle will be pairing with itself: og for k=10, we pair mod=5 with mod=5. So should be divisible by 2
        if(k%2== 0 && freq[k/2]%2!=0) return false;

        return true;
    }
};