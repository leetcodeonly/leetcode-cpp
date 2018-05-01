class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> mp;
        assert(nums.size() >= 2);
        std::vector<int> ret;
        mp[nums[0]] = 0;
        for(int i=1; i<nums.size(); i++) {
            auto it = mp.find(target - nums[i]);
            if(it != mp.end()) {
                ret.push_back(it->second);
                ret.push_back(i);
                return ret;
            }
            mp[nums[i]] = i;
        }
        return ret;
    }
};

