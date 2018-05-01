class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> path;
        vector<vector<int>> out;
        for(int i=0; i<=nums.size(); i++) {
            rec(nums, 0, used, path, i, out);
        }
        return out;
    }
    
    void rec(vector<int>& nums, int start, vector<bool>& used, vector<int>& path, int size, vector<vector<int>>& out) {
        if(path.size() == size) {
            out.push_back(path);
            return;
        }
        for(int i=start; i<nums.size(); i++) {
            if(used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            rec(nums, i+1, used, path, size, out);
            path.pop_back();
            used[i] = false;
        }
    }
};

