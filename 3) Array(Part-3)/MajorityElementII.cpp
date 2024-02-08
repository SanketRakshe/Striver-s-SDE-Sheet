class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0, count2 = 0;
        int element1 = INT_MIN;
        int element2 = INT_MIN;

        for(int i=0; i<n; i++) {
            if(count1 == 0 && element2 != nums[i]) {
                element1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0 && element1 != nums[i]) {
                element2 = nums[i];
                count2 = 1;
            }
            else if(nums[i] == element1) {
                count1++;
            } 
            else if(nums[i] == element2) {
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        vector<int> ans;
        count1 = 0, count2 = 0;

        for(int i=0; i<n; i++) {
            if(nums[i] == element1) count1++;
            if(nums[i] == element2) count2++;
        }

        int mini = int(n/3) + 1;

        if(count1 >= mini) ans.push_back(element1);
        if(count2 >= mini) ans.push_back(element2);

        return ans;

    }
};