class Solution {
public:
    int candy(vector<int>& ratings) {
        // Two pass greedy. Difficult in name, but easy once approach clicks
        int n=ratings.size();
        vector<int> candies(n, 1);

        for(int i=1; i<n; i++){
            if(ratings[i]> ratings[i-1])    candies[i]= candies[i-1]+1;
            // Ensures increasing ratings get increasing candies compared to left neighbors
        }

        // Right neighbors
        for(int i=n-2; i>=0; i--){
            if(ratings[i]> ratings[i+1])    //cases: either already has more candies meaning no update, or not meaning update by candies[i+1]+1
                candies[i]= max(candies[i], candies[i+1]+1);
        }

        //Return Total candies
        return accumulate(candies.begin(), candies.end(), 0);
    }
};