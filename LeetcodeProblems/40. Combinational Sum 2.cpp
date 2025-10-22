class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target, int start = 0) {
        if (start == 0) sort(candidates.begin(), candidates.end());

        if (target == 0) return {{}};

        vector<vector<int>> result;

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] > target) break;

            auto combos = combinationSum2(candidates, target - candidates[i], i + 1);
            for (auto& combo : combos) {
                combo.push_back(candidates[i]);
                result.push_back(combo);
            }
        }
        return result;
    }
};
