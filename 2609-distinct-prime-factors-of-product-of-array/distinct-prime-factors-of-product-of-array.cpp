class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int maxVal= *max_element(nums.begin(), nums.end());
        vector<int> spf(maxVal+1);
        for(int i=2; i<=maxVal; i++)    spf[i]=i;

        for(int i=2; i*i<=maxVal; i++){
            if(spf[i]==i){
                for(int j=i*i; j<=maxVal; j+=i){
                    if(spf[j]==j)    spf[j]=i;  // Set only if not already set
                }
            }
        }

        unordered_set<int> distinctPrimes;

        for(int n: nums){
            while(n>1){
                int p= spf[n];
                distinctPrimes.insert(p);
                // Optimization: divide all instances of this prime
                while(n%p==0)   n/=p;
            }
        }
        return distinctPrimes.size();

    }
};