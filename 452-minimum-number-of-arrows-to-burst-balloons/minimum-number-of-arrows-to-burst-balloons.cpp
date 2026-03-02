class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
            return a[1]< b[1];
        });
        int arrows=1, curr_point= points[0][1], i=1;
        while(i< points.size()){
            if(points[i][0]<= curr_point)    i++;
            else{
                curr_point=points[i++][1];
                arrows++;
            }
        }
        return arrows;
    }
};