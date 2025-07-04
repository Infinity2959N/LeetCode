class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        
        int arrows= 1;
        int arrowPos= points[0][1]; //Keep at end position of the first sorted index
        int n= points.size();

        for(int i=1; i<n; i++){
            if(points[i][0]> arrowPos){
                arrows++;
                arrowPos= points[i][1];
            }
        }
        return arrows;
    }
};