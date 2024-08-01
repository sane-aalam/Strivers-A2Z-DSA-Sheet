// Recursion + memorization 
#include <bits/stdc++.h> 
/*
 1. Express Everything in terms of indexes(index,target);
 2. Explore possiblity on that indexes
 3. return output
*/
bool solve(int index, int target, vector<int> & arr, 
        vector<vector<int>> &dp){

   // base cases
   // target become zero
    if(target == 0){
        return true;
    }
    
    if(index == 0){
        return arr[0] == target;
    }

    if(dp[index][target] != -1){
        return dp[index][target];
    }

    bool not_pick = solve(index-1,target,arr,dp);
    bool pick = false;
    if(arr[index] <= target){
        pick = solve(index-1,target-arr[index],arr,dp);
    }
    return dp[index][target] = not_pick or pick;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    int index = n - 1;
    int target = k;
    vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
    bool ans = solve(index,target,arr,dp);
    return ans;
}