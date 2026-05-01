class Solution {
public:
    int findTheWinner(int n, int k) {
        // circle: 1-n
        // moving clockwise from ith friend brings you to i+1th friend for 1<=i<n, and moving clockwise from nth brings back to 1st
        // Start at 1, count next k friends (incnluding the one you started at)
        // Last friend you counted leaves the circle and loses
        // if still more than one friend left, repeat
        // Last remaining friend will be the winner

        // Approach 1: Simulation

        // Approach 2: Recursion with subproblem

        // Approach 3: Bottom up DP
        int res=0;
        for(int player_num=2; player_num<=n; player_num++){
            res= (res+k)% player_num;
        }
        return res+1;
    }
};