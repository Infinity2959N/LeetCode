class Solution {
public:
    int smallestValue(int n) {
        // SPF-> Find all prime factors-> calculate sum-> find all prime factors-> calculate sum->...
        // The "4" trap: 4= 2x2; 2+2= 4; 4=2x2.. infinite loop. if currentSum==n, break.
        // Precompute SPF up to the initial n
        vector<int> spf(n + 1);
        for (int i = 2; i <= n; i++) spf[i] = i;
        for (int i = 2; i * i <= n; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= n; j += i)
                    if (spf[j] == j) spf[j] = i;
            }
        }

        while (true) {
            int currentSum = 0;
            int temp = n;
            
            // Factorize and sum
            while (temp > 1) {
                currentSum += spf[temp];
                temp /= spf[temp];
            }

            if (currentSum == n) break; // The "4" trap and Prime stopping condition
            n = currentSum;
        }
        return n;
    }
};