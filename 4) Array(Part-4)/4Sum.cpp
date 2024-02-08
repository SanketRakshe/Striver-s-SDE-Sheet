class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        /*
        int n = nums.size();
        set<vector<int>> st;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    for(int l=k+1; k<n; k++) {
                        long long sum = nums[i] + nums[j];
                        sum += nums[k];
                        sum += nums[l];

                        if(sum == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
        */
        



        /*
        //Better Solution
        set<vector<int>> st;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                //for storing the kth element & searching for the fourth element in it 
                set<long long> hashset;
                for(int k=j+1; k<n; k++) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;
                    //checking the fourth element is present into the set or not
                    if(hashset.find(fourth) != hashset.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    //put the kth element into the hashset
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
        */


        //Optimal Solution:
        vector<vector<int>> ans;
        int n = nums.size();
        
        //Sort the given vector
        sort(nums.begin(), nums.end());

        //find out the quadruplets
        for(int i=0; i<n; i++) {
            //Avoiding duplicate while moving i
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j=i+1; j<n; j++) {
                //Avoiding duplicates while moving j
                if(j > i+1 && nums[j] == nums[j - 1]) continue;

                int k = j + 1;
                int l = n - 1;

                while(k < l) {
                    //calculate the sum 
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    
                    if(sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;

                        //Avoiding the duplicates while moving k & l
                        while(k < l && nums[k] == nums[k - 1]) k++;
                        while(k < l && nums[l] == nums[l + 1]) l--;
                    }
                    else if(sum < target) {
                        k++;
                    }
                    else l--;
                }
            }
        }
        return ans;

        //TC = O(N3), where N = size of the array.
        //SC = O(no. of quadruplets)
    }
};