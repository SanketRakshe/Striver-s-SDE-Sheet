class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        //Brute Force
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                int sum = nums[i] + nums[j];
                if(sum == target) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
        //We are ending up this solution on T.C = O(N*N) and S.C = O(N)
        */



        //Better Solution than Brute Force
        //Creating a map to store the values that are not getting results now but may be used in further operations
        //nums[i] + x = target
        // x = target - nums[i]
        // Check that x present in your map or not if it is present then the current index and x's index are your required indexes..
        unordered_map<int, int> mapp;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            int num = nums[i];
            int moreNeeded = target - num;
            if(mapp.find(moreNeeded) != mapp.end()) {
                return {i, mapp[moreNeeded]};
            }
            mapp[num] = i;
        }
        return {-1, -1};
        //Wrapping this solution with the T.C = O(N) for the traversal of entire array and serching of map takes O(1) then we'll ending on this O(N)
        //S.C = O(N) this space are required for the unordered mapp




        //We can Optimized the space complexity further using two pointers but that approach we have to sort the array and hense the entire order get changed then required indexes has been changed thats why we are ending up this solution on O(N)TC and O(N)SC..


    }
};