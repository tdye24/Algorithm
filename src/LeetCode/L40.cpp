class Solution {
public:
    void dfs(vector<vector<int>>& results, vector<int>& result, vector<int>& candidates, int target, int level) {
        //boundary
        if(target == 0) {
            results.push_back(result);
            return;
        } 
        //find
        for(int i=level; i<candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > level && candidates[i] == candidates[i - 1]) {
                continue;
            }
            result.push_back(candidates[i]);
            dfs(results, result, candidates, target - candidates[i], i+1);
            result.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results{};
        vector<int> result{};
        sort(candidates.begin(), candidates.end());
        dfs(results, result, candidates, target, 0);
        return results;
    }

};
