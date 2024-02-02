class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1
        int i = n - 1;
        while (i > 0 && nums[i-1] >= nums[i]) {
            i--;
        }
        
        // Step 2
        if (i > 0) {
            int j = n - 1;
            while (nums[j] <= nums[i-1]) {
                j--;
            }
            swap(nums[i-1], nums[j]);
        }
        
        // Step 3
        reverse(nums.begin() + i, nums.end());
    }
};