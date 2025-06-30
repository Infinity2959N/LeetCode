class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Approach: Step 1: sort based on heights (desc), if equal heights, sort based on k (asc)
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0]!= b[0]) return a[0] > b[0];
            else return a[1] < b[1];
        });

        // Why desc?: because we are inserting into a stack, meaning the previous value will slide to next index automatically

        // Step 2: insert all elements into resultant vector in the kth index(Stack)
        vector<vector<int>> result;
        for(const vector<int>& person: people){
            result.insert(result.begin()+ person[1], person);
        }

        return result;
        
    }
};