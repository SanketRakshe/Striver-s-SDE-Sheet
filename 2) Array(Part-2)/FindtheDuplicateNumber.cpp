class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n-1; i++) {
            if(nums[i] == nums[i+1]) {
                return nums[i];
            }
        }
        //TC = O(NlogN)
        //SC = O(1)
        */


        /*
        int n = nums.size();
        vector<int> freq(n, 0);

        for(int i=0; i<n; i++) {
            if(freq[nums[i]] == 0) {
                freq[nums[i]]++;
            }
            else {
                return nums[i];
            }
        }
        //TC = O(N)
        //SC = O(N)
        */


        /*
        map<int, int> m;
        int dplicate = 0;

        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        for(auto i: m) {
            if(i.second > 1) {
                return i.first;
            }
        }
        //TC = O(logN)
        //SC = O(N)
        */

        /*
        //Optiized Binary Search Approach:

        int n = nums.size();
        //first define the start, end boundaries
        int s = 0;
        int e = n-1;

        while(s<e) {
            int mid = s+(e-s)/2;
            int count = 0;
            //for each mid point value mid within the range,
            //count the number of elements in nums that are less than or equal to mid.
            for(auto num: nums) {
                if(num <= mid) {
                    count++;
                }
            }
            //If the count is greater than mid,
            //it means there are duplicates in the range [1, mid],
            //so update the search range to [1, mid]. Otherwise, 
            //update the search range to [mid + 1, n].
            if(count > mid) {
                e = mid;
            }
            else {
                s = mid+1;
            }
        }
        return s;

        //TC = O(logn)
        //SC = O(N)

        */

        int slow = nums[0];
        int fast = nums[0];

        do{
            slow  = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        fast = nums[0];

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};