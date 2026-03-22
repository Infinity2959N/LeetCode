class Solution {
    typedef long long ll;
    ll gcd(ll a, ll b){ return b==0? a: gcd(b, a%b);}
    ll lcm(ll a, ll b){ 
        if (a==0 || b==0)
            return 0;
        ll res= a/gcd(a, b)* b;
        if (res>1000) return 1001;
        return res;
    }
public:
    int subarrayLCM(vector<int>& nums, int k) {
        // Sliding window fails here
        // Constraints: length and k<=1000 so brute force works here: O(n^2)
        // Optimization: Pruning: currentLCM > k or k % currentLCM != 0, there is no point in continuing the j loop.
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            ll currentLCM = nums[i];
            for (int j = i; j < n; j++) {
                currentLCM = lcm(currentLCM, (ll)nums[j]);
                
                if (currentLCM == k) {
                    count++;
                } else if (currentLCM > k || k % currentLCM != 0) {
                    // Once LCM exceeds k or isn't a factor of k, 
                    // no more numbers can bring it back to k.
                    break; 
                }
            }
        }
        return count;
    }
};