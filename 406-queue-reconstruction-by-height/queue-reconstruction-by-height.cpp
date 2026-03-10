class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // h=height, k= how many people (taller or equal) are allowed in front of you
        // Logic: Sort people by height descending, if same height, sort by k ascending
        // Insert each in the result at the index equal to their k

        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[0]==b[0])
                return a[1]<b[1];   // if height same: sort by k ascending
            return a[0]> b[0];  // sort by height descending: Why? Taller people don't care about how many short people come in front of them
        });

        // Step 2: Insert into vector at index k
        vector<vector<int>> res;
        for(const auto& p: people){
            res.insert(res.begin()+p[1], p);    // Insert at k'th position
        }
        return res;
    }
};