class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // Segmented Sieve for finding prime within a range of left to right
        /* Approach:
        1. Pre sieve to find all primes upto sqrt(right): basePrimes
        2. Create a dummy bool array of size right-left+1. Idx 0 is left, i is left+i
        3. Map small primes to the range:
            foe every prime p in basePrimes:
            1. Find first multiple of p that is >= left
            Formula: start= max(p*p, ((left+p-1)/p)*p)
            Formula expalined: (left+p-1)/p is a trick to find the ceil(left/p). Multiplying back by p gives the actual multiple. 
                It's possible the ceil may return the prime number itself (eg, when calculating for left=2), so we check max(p*p, ceil(left/p)*p) to make sure we always start with p^2 or higher.
            2. Iterate from start to right in steps of p, and mark isPrimeRange[i-left] as false.
        */

        int limit = sqrt(right);
        vector<bool> isBasePrime(limit + 1, true);
        isBasePrime[0] = isBasePrime[1] = false;

        // Phase 1: Pre-Sieve up to sqrt(right)
        for (int i = 2; i * i <= limit; i++) {
            if (isBasePrime[i]) {
                for (int j = i * i; j <= limit; j += i)
                    isBasePrime[j] = false;
            }
        }

        vector<int> primes;
        for (int i = 2; i <= limit; i++) {
            if (isBasePrime[i]) primes.push_back(i);
        }

        // Phase 2: Range Sieve
        vector<bool> isPrimeRange(right - left + 1, true);
        if (left <= 1) {
            // Explicitly handle 1 if it's in the range
            if (right >= 1) isPrimeRange[1 - left == 0 ? 0 : 1 - left] = false; 
            // Simpler: just handle the 1st index specifically if left is 1
            if(left == 1) isPrimeRange[0] = false;
            if(left == 0) { isPrimeRange[0] = false; if(right >= 1) isPrimeRange[1] = false; }
        }

        for (int p : primes) {
            // Use the formula we discussed
            long long start = max((long long)p * p, (long long)(left + p - 1) / p * p);
            for (long long j = start; j <= right; j += p) {
                isPrimeRange[j - left] = false;
            }
        }

        // Phase 3: Collect and Compare
        vector<int> found;
        for (int i = 0; i < isPrimeRange.size(); i++) {
            if (isPrimeRange[i]) found.push_back(i + left);
        }

        if (found.size() < 2) return {-1, -1};

        int minDiff = INT_MAX;
        vector<int> res = {-1, -1};
        for (int i = 0; i < (int)found.size() - 1; i++) {
            int diff = found[i+1] - found[i];
            if (diff < minDiff) {
                minDiff = diff;
                res = {found[i], found[i+1]};
                // Optimization: Twin primes (diff == 2 or 1 for prime 2,3) 
                // are the smallest possible difference. We can exit early.
                if (minDiff <= 2) return res;
            }
        }

        return res;

    }
};