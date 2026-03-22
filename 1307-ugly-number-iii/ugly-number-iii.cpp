class Solution {
    // Use long long to prevent overflow during intermediate multiplication
    typedef long long ll;

    ll gcd(ll a, ll b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    ll lcm(ll a, ll b) {
        // Divide first to delay overflow as much as possible
        return (a / gcd(a, b)) * b;
    }
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        // How binary search works here: We select a number, say X, and quickly calculate how many numbers less than X are divisible by a, b or c. If it's more than n, we go left else right
        // The math: Inclusion Exclusion Principle: f(x)= x/a+ x/b+ x/c- x/(lcm(a,b)) -x/lcm(b,c) -x/lcm(a,c)+1 x/lcm(a,b,c)
        // LCM optimization: Multiplicaton may lead to overflow, so divide first: (a/gcd(a,b))*b

        ll la = a, lb = b, lc = c;
        
        // Pre-calculate all denominators for the IEP formula
        ll ab = lcm(la, lb);
        ll bc = lcm(lb, lc);
        ll ac = lcm(la, lc);
        ll abc = lcm(la, bc); // LCM(a, LCM(b, c))

        ll low = 1, high = 2e9; 
        ll ans = high;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            
            // Inclusion-Exclusion Principle
            ll count = mid/la + mid/lb + mid/lc 
                     - mid/ab - mid/bc - mid/ac 
                     + mid/abc;

            if (count >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};