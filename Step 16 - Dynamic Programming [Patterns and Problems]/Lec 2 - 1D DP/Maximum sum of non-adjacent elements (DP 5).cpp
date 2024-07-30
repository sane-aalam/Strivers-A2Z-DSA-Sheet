
/* Problem statement  → 198. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/

/* 
1 → DP solution [ Using Recursion ]
  → Express Everything in terms of index
  → Do all the stuff on that index
  → According to quesiton [find min, max, sum-up,longest, shortest,total number of ways]
*/

class Solution {
private:
   int HouseRobber(vector<int> & nums, int index){

    // → base case
       if(index == 0){
         return nums[index];
       }
    // → When you are gonna to (index-2) last case 
    // → suppose you can index-2, Negative index, you can 
    // → Then you can return 0 (no array elements is present on negative indexes value)
       if(index < 0){
        return 0;
       }
    // →  it will automatically contact the police if two adjacent houses were broken into on the same night.
       int pick = nums[index] + HouseRobber(nums,index-2);
       int notPick = 0 + HouseRobber(nums,index-1);
    // → maximum amount of money you can rob tonight without alerting the police.
       return max(pick,notPick);
   }
public:
    int rob(vector<int>& nums) {
        int index = nums.size() - 1;
        // → recursive function calls 
        int maximumAmount = HouseRobber(nums,index);
        return maximumAmount;
    }
};

/*
2 → DP solution [memorization]
  → Identification of overlapping problems
  → Reduce the overlapping recursive calls
  → Create Array/Matrix using changeable variables
  → Store the recursive calls
  → Re-use the recursive calls
*/


class Solution {
private:
   int HouseRobber(vector<int> & nums, int index,vector<int> & dp){

    // → base condition
       if(index == 0){
         return nums[index];
       }
    // → When you are gonna to (index-2) last case 
    // → suppose you can index-2, Negative index, you can 
    // → Then you can return 0 (no array elements is present on negative indexes value)
       if(index < 0){
        return 0;
       }

       if(dp[index] != -1){
        return dp[index];
       }

    
    // →  it will automatically contact the police if two adjacent houses were broken into on the same night.
       int pick = nums[index] + HouseRobber(nums,index-2,dp);
       int notPick = 0 + HouseRobber(nums,index-1,dp);
    // → maximum amount of money you can rob tonight without alerting the police.
       return dp[index] = max(pick,notPick);
   }
public:
    int rob(vector<int>& nums) {
        int index = nums.size() - 1;
        // → recursive function calls 
        vector<int> dp(nums.size() + 1, -1);
        int maximumAmount = HouseRobber(nums,index,dp);
        return maximumAmount;
    }
};


/*
3 → DP solution [Tabulation]
  → Create matrix/Array using changeable variables
  → convert the base condition into initialization of DP array/Matrix
  → Copy the recurrence relation [fill using iterative way]
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        dp[0] = nums[0];

        for(int i = 1; i<nums.size(); i++){
            int pick = nums[i];
            if (i > 1)
                  pick += dp[i - 2];
             int notPick = 0 + dp[i-1];
            // maximum amount of money you can rob tonight
             dp[i] = max(pick,notPick);
        }
        return dp[n-1];
    }
};

/*
4 → DP solution [ Optimizing Space complexity ]
  → If you don't know Space Optimization, you don't know DP.
  → According to the question, do you really need an array or matrix?
  → Either You can just need Last Two value
  → prev_value1 and prev_value2, to Calculate current_value
  → Inorder to remove the extra space complexity
  → we can use DP on space Optimization.
  → prev2_i prev_i curr_i
  → create famous pointers, update pointers 
    prev2_i become prev_i
    prev_i become curr_i
*/



class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int prev_i = nums[0];
        int prev2_i = 0;
        int curr_i = 0;

        for(int i = 1; i<nums.size(); i++){
            int pick = nums[i];
            if (i > 1)
                  pick += prev2_i;
             int notPick = 0 + prev_i;
            // maximum amount of money you can rob tonight
            curr_i = max(pick,notPick);
            prev2_i = prev_i;
            prev_i = curr_i;
        }

        return prev_i;
    }
};

/*
TC- o(N)
SC -o(1)
*/