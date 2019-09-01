class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results{};
        vector<int> result{};
        dfs(results, result, n, k, 1);
        return results;
    }
    
    void dfs(vector<vector<int>>& results, vector<int>& result, int n, int k, int level) {
    	//boundary
		if(result.size() == k) {
    		results.push_back(result);
    		return;
		}
		//find
		for(int i=level; i<=n; i++) {
			result.push_back(i);
			dfs(results, result, n, k, i+1);
			result.pop_back();
		} 
	}
};
