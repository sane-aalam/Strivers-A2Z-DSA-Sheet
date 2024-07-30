#include <bits/stdc++.h> 
#define MOD 1000000007 

// 1 → DP solution [ Using Recursion ]
//   → Express Everything in terms of index
//   → Do all the stuff on that index
//   → According to question [find min, max, sum-up,longest, shortest,total number of ways]

// 2 → DP solution [memorization]
//   → Identification of overlapping problems
//   → Reduce the overlapping recursive calls
//   → Create Array/Matrix using changeable variables
//   → Store the recursive calls
//   → Re-use the recursive calls

// 3 → DP solution [Tabulation]
//   → Create matrix/Array using changeable variables
//   → convert the base condition into initialization of DP array/Matrix
//   → Copy the recurrence relation [fill using iterative way]


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

// 4 → DP solution [ Optimizing Space complexity ]
//   → If you don't know Space Optimization, you don't know DP.
//   → According to the question, do you really need an array or matrix?
//   → Either You can just need Last Two value
//   → prev_value1 and prev_value2, to Calculate current_value
//   → Inorder to remove the extra space complexity
//   → we can use DP on space Optimization.

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