class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, blue = nums.size() - 1;
        for(int i=0; i<=blue; i++) {
            if(nums[i] == 0) {
                std::swap(nums[i], nums[red]);
                red++;
            } else if (nums[i] == 2) {
                std::swap(nums[i], nums[blue]);
                blue--;
                i--;
            }
        }
    }
};
