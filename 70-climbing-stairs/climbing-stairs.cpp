class Solution {
public:
    int climbStairs(int n) {
        // Simple fibonacci pattern
        if(n<=2) return n;
        int temp1=1, temp2=2, temp3=0;
        
        for(int i=3; i<=n; i++){
            temp3= temp1+temp2;
            temp1=temp2;
            temp2=temp3;
        }
        return temp3;
    }
};