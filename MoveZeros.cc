class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonz = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                nums[nonz] = nums[i];
                nonz++;
            }
        }
        for(int i=nonz; i<nums.size(); i++){
            nums[i] = 0;
        }
    }
};

