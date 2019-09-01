#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> results{};
	vector<int> result{};
	sort(candidates.begin(), candidates.end());
	dfs(results, result, candidates, target, 0);
	return results;
}

void dfs(vector<vector<int>>& results, vector<int>& result, vector<int>& candidates, int target, int level) {
	//boundary
	if(target == 0) {
		results.push_back(result);
		return;
	} 
	//find
	for(int i=level; i<candidates.size() && target - candidates[i] >= 0; i++) {
		result.push_back(candidates[i]);
		dfs(results, result, candidates, target - candidates[i], i);
		result.pop_back();
	}
}

int main() {
	
}
