class Solution {
public:
    int candy(vector<int>& ratings) {
        // Requires O(n) complexity: Possible solutions: Either 2 pointer or two pass greedy (Greedy being the one that will work here)
        // Double pass greedy:
        // Pass 1: Ensure child has more candy than it's left neighbor if higher rating
        // Pass 2: Ensure child has more candy than right neighbor if higher rating
        int n= ratings.size();
        vector<int> candies(n, 1); // Everyone starts with 1 candy

        // Left to right
        for(int i=1; i<n; i++){
            if(ratings[i]> ratings[i-1])    candies[i]= candies[i-1]+1;
        }

        // Right to left
        for(int i=n-2; i>=0; i--){
            if(ratings[i]> ratings[i+1])    candies[i]=max(candies[i], candies[i+1]+1);
        }
        int total=0;
        for(int c: candies){
            total+= c;
        }

        return total;
    }
};