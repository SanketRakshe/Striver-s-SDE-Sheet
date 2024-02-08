class Solution {
public:
    int solveRec(int row, int col, vector<vector<int>> &dp) {
        //base case
        if(row == 0 && col == 0) {
            return 1;
        }

        if(row < 0 || col < 0)
        return 0;

        if(dp[row][col] != -1) return dp[row][col];

        int up   = solveRec(row-1, col, dp);
        int left = solveRec(row, col-1, dp);

        return dp[row][col] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solveRec(m-1, n-1, dp);
    }
};