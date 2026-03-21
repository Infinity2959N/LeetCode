class Solution {
public:
    int countPrimes(int n) {
        /* Sieve of Eratosthenes: O(nloglogn) ~ O(n)
        Concept: Start from 2. If it's prime, mark all it's multiples as non prime, move to next unmarked number and mark it's multiples, only need to check till root n*/
        if(n<2) return 0;
        vector<int> isPrime(n, 1);
        isPrime[0]=0;
        isPrime[1]=0;

        int numPrime=0;
        int i;
        for(i=2; i*i<n; i++){
            if(isPrime[i]){
                numPrime++;
                for(int j=i*i; j< n; j+=i){
                    isPrime[j]=0;
                }
            }
        }
        while(i<n){
            if(isPrime[i++])    numPrime++;
        }
        return numPrime;

    }
};