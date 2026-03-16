class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1]< b[1];
        });

        int length=0;
        int currEnd= -1001; // Better practice to default with LONG_LONG_MIN for no risk programming in OA situations
        for(const auto& pair: pairs){
            if(pair[0]> currEnd){
                length++;
                currEnd= pair[1];
            }
        }
        return length;

    }
};