class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        // Binary search+ inclusion exclusion principle
        // Find smallest x such that count(x)>=n , where count(x)= total number(<x) divisible by a, b or c
        
        long long left= 1, right= 2e9;
        while(left<right){
            long long mid= left+ (right-left)/2;
            if(count(mid, a, b, c)< n){
                left=mid+1;
            }else{
                right= mid;
            }
        }
        return (int)left;
    }
private:
    long long count(long long x, long long a, long long b, long c){
        long long ab= lcm(a,b);
        long long ac= lcm(a,c);
        long long bc= lcm(b,c);
        long long abc= lcm(ab,c);

        return (x/a)+ (x/b)+ (x/c)- (x/ab)- (x/bc)- (x/ac)+ (x/abc);
    }

    long long lcm(long long x, long long y){
        return x*y/ __gcd(x, y);
    }
};