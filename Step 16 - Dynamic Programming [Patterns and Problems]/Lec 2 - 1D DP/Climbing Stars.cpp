#include <bits/stdc++.h> 
#define MOD 1000000007 

// DP solution → Memorization for reduce the number of recursive calls 

int totalNumberWays(int n, vector<int> & dp){

    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 1;
    }

    // MEMORIZATION - reduce the number of recurisve calls
    if(dp[n] != -1){
        return dp[n];
    }

    int oneSteps = totalNumberWays(n-1,dp);
    int twoSteps = totalNumberWays(n-2,dp);

    return dp[n] = (oneSteps + twoSteps) % MOD;
}

int countDistinctWays(int nStairs) {
    //  Write your code here.
    int n = nStairs;
    vector<int> dp(n+1,-1);
    return totalNumberWays(n,dp);
}

// DP solution → Optimizing Space complexity
// You are better than 99.19%
#include <bits/stdc++.h> 

    int countDistinctWays(int nStairs) {
        //  Write your code here.
            int prev_i = 1;
            int prev2_i = 1;

            for(int i = 2; i<=nStairs; i++){
                int curr_i = (prev_i + prev2_i) % 1000000007;
                prev2_i = prev_i;
                prev_i = curr_i;
            }
            return prev_i;
    }