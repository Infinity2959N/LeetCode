class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)    return x;

        int left=2, right=x;
        while(left<=right){
            int mid= left+ (right-left)/2;
            long long square=(long long)mid*mid;
            if(square > x){
                right=mid-1;
            }else if(square < x){
                left= mid+1;
            }else{
                return mid;
            }
        }
        return right;
    }
};