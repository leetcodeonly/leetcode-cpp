class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> path;
        vector<vector<int>> out;
        rec(nums, used, path, out);
        return out;
    }
    
    void rec(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& out) {
        if(path.size() == nums.size()) {
            out.push_back(path);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(used[i]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            rec(nums, used, path, out);
            used[i] = false;
            path.pop_back();
        }
    }
};
