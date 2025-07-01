class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low= *max_element(weights.begin(), weights.end());
        int high= accumulate(weights.begin(), weights.end(), 0);

        while(low<=high){
            int mid= low+(high-low)/2;
            if(canShip(weights, days, mid)){
                high= mid-1;
            }else{
                low= mid+1;
            }
        }
        return low;
    }
private: 
    bool canShip(vector<int>& weights, int totalDays, int maxAllowedWeight){
        int currDays=1;
        int currLoad=0;

        for(int weight: weights){
            if(currLoad+ weight> maxAllowedWeight){
                currDays++;
                currLoad= weight;
                if(currDays> totalDays) return false;
            }
            else{
                currLoad+= weight;
            }
        }
        return true;
    }
};