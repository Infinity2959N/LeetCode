class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       // Solution: Sort the list, then merge taking start of the first and end of the last
        sort(intervals.begin(), intervals.end());
        int left= intervals[0][0], right= intervals[0][1];

        vector<vector<int>> ans;

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<= right){
                right= max(right, intervals[i][1]);
            }
            else{
                ans.push_back({left, right});
                left= intervals[i][0];
                right= intervals[i][1];
            }
        }
        ans.push_back({left, right});
        return ans;
    }
};