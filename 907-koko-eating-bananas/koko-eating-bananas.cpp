class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // n piles. ith pile has piles[i] bananas, guards wll come back in h hours
        // banana eating speed is k. We have to return the minimum k that allows koko to eat all bananas within  hours.

        // Approach: Apply binary search on the range of k. If she can't eat all bananas within the current k, search in right of k, else store k as temporary answer and search on left of k.

        // Selecting the range of k: Atleast 1 to atmost the size of the largest pile.
        auto max_el= max_element(piles.begin(), piles.end());
        int k= *max_el;

        int low=1, high=k;
        while(low<= high){
            int mid= low+ (high-low)/ 2;
            if(valid(mid, piles, h)){
                k= mid;
                high= mid-1;
            }else{
                low= mid+1;
            }
        }
        return k;
    }
private:
    bool valid(int k, vector<int> &piles, int h){
        // To check if Koko can eat all bananas in h hours at k rate
        long long tot_hrs= 0;
        for(int i: piles){
            tot_hrs+= (i+k-1)/k;    // Essentially calculating ceil of [pile/k] that will find total hours koko will spend on i'th pile at k speed. The function is a mathematical "trick" to calculate the ceil
        }
        return tot_hrs<= h;
    }
};