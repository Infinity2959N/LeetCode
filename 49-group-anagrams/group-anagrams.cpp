class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> set;

        for(const string& s: strs){
            string key=s;
            sort(key.begin(),key.end());
            set[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto& entry : set){
            result.push_back(entry.second);
        }
        return result;
    }
};