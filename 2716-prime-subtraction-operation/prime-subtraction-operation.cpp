class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int  maxVal= *max_element(nums.begin(), nums.end());
        vector<int> isPrime(maxVal, 1);
        for(int i=2; i*i<maxVal; i++){
            if(isPrime[i]==1){
                for(int j=i*i; j< maxVal; j+=i){
                    isPrime[j]=0;
                }
            }
        }
        vector<int> primes;
        for(int i=2; i<maxVal; i++){
            if(isPrime[i])  primes.push_back(i);
        }

        // After sieving into vector<int> primes...
        //num[i]-p > prev || p< nums[i]-prev -> threshold= nums[i]-prev-1
        // lower bound finds the first element smaller than or equal to threshold in the sorted primes array
        // To find the largest such element, we move the elements back to the array
        int prev = 0;
        for (int& x : nums) {
            int threshold = x - prev - 1;
            if (threshold >= 2) { // Smallest prime is 2
                // Find first prime > threshold, then move back one
                auto it = lower_bound(primes.begin(), primes.end(), threshold + 1);
                if (it != primes.begin()) {
                    x -= *(--it);
                }
            }
            
            if (x <= prev) return false; // Greedy failed
            prev = x;
        }
        return true; 
    }
};