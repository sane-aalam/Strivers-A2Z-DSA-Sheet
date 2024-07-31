
/*
You are given an n rows and m cols matrix grid representing a field of chocolates where grid[i][j] represents the number of chocolates that you can collect from the (i, j) cell.

You have two robots that can collect chocolates for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of chocolates collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all chocolates, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the chocolates.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
*/

#include <bits/stdc++.h> 

int solve(int i, int j1, int j2, int n, int m,
 vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){

       if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9; // A

        if(i == n-1){
            if(j1 == j2){
                return grid[i][j1];
            }else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        
        // memorization using 3-Dp matrix 
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = INT_MIN;
         for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                int ans;
                if(j1 == j2){
                    ans = grid[i][j1] + solve(i+1,di+j1,dj+j2,n,m,grid,dp);
                }else{
                    ans = grid[i][j1] + grid[i][j2] + solve(i+1,di+j1,dj+j2,n,m,grid,dp);
                }
                maxi = max(ans,maxi);
            }    
        }
        return dp[i][j1][j2] = maxi;
 }
    
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();

    // There are three changable variable in recursion(i,j1,j2)
    // Create dp[i][j1][j2] using vector to memorization our code
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
}