class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        // n baskets at positions i, m balls
        // To distribute such that min magnetic force between any two balls is maximum
        // Approach: Try binary search on possible distances to find max possible valid distance greedily
        // max possible distance: max of positions/m-1
        int n= position.size();

        sort(position.begin(), position.end());
        int maxi= position[n-1]-position[0];
        int left= 1, right= maxi/(m-1);

        int maxMin=-1;
        while(left<=right){
            int mid= (left+right)/2;

            if(canBuild(mid, m, position)){
                maxMin=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return maxMin;
    }
private:
    bool canBuild(int dist, int balls, vector<int> positions){
        int countBalls=1;
        int lastPlaced= positions[0];
        for(int i=1; i<positions.size(); i++){
            if(positions[i]-lastPlaced>=dist){
                countBalls++;
                lastPlaced= positions[i];
            }
            if(countBalls>=balls) return true;
        }
        return false;
    }
};