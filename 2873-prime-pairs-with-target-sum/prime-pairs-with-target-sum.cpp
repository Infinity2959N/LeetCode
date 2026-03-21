class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        // Sieve-> find pairs
        if(n<2) return {};
        vector<int> isPrime(n, 1);
        isPrime[0]=0;
        isPrime[1]=0;


        for(int i=2; i*i<n; i++){
            if(isPrime[i]){
                for(int j=i*i; j<n; j+=i){
                    isPrime[j]=0;
                }
            }
        }

        vector<vector<int>> pairs;

        for(int i=2; i<n/2+1; i++){
            if(isPrime[i] && isPrime[n-i]){
                pairs.push_back({i, n-i});
            }
        }
        return pairs;
    }
};