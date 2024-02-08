#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  int n = arr.size();
  int left = 0, right = 0;
  int sum = arr[0], maxLen = INT_MIN;
  while(right < n) {
    while(left <= right && sum > 0) {
      sum -= arr[left];
      left++;
    }

    if(sum == 0) {
      maxLen = max(maxLen, right - left + 1);
    }
    right++;
    if(right < n) {
      sum += arr[right];
    }
  }
  return maxLen;
}