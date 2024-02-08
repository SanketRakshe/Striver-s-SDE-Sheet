class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        if(str.size() == 0)
        return 0;

        unordered_set<int> st;
        int left = 0;
        int maxLen = INT_MIN;
        int n = str.length();

        for(int r=0; r<n; r++) {
            if(st.find(str[r]) != st.end()) {
                while(left < r && st.find(str[r]) != st.end()) {
                    st.erase(str[left]);
                    left++;
                }
            }
            st.insert(str[r]);
            maxLen = max(maxLen, r - left +1);
        }
        return maxLen;
    }
};