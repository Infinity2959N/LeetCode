        // Topological sort+ backtracking
        // Hard problem: may cause cycles (deadlock style: recipe a may need recipe b and vice versa)
        // The hard part is creating the graph, rest is standard topo sort


class Solution {
    
    unordered_map<string, vector<string>> adj;
    unordered_set<string> supplies_set;
    unordered_map<string, int> memo;    // 1: visiting, 2: can make, 3: can't
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        for(string s: supplies) supplies_set.insert(s);
        for(int i=0; i<recipes.size(); i++) adj[recipes[i]]= ingredients[i];

        vector<string> result;

        for(string& recipe: recipes){
            if(canCraft(recipe)) result.push_back(recipe);
        }
        return result;
    }
private:
    bool canCraft(string& item){
        // If already in supplies set
        if(supplies_set.count(item)) return true;
        // If not a recipe and not a supply
        if(!adj.count(item)) return false;

        // Cycle detection
        if(memo[item]==1) return false;
        // memo check
        if(memo[item]==2) return true;
        if(memo[item]==3) return false;

        // mark as visited
        memo[item]=1;

        for(string& ingredient: adj[item]){
            if(!canCraft(ingredient)){
                memo[item]= 3;
                return false;
            }
        }
        memo[item]= 2;
        return true;
    }
};