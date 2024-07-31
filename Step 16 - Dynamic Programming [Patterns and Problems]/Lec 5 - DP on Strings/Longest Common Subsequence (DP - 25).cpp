/*
1 → DP solution [ Using Recursion ]
  → Express Everything in terms of index
  → Do all the stuff on that index [matching both of string or not]
  → According to question [find min, max, sum-up,longest, shortest,total number of ways]
*/

class Solution {
  private:
   int solve(string str1, string str2, int index1, int index2){
       
       if(index1 == 0 or index2 == 0){
           return 0;
       }
      
      // there is one common subsequence of both of string return 1,
       if(str1[index1-1] == str2[index2-1]){
           return 1 + solve(str1, str2, index1-1, index2-1);
       }else{
        //   there is no common subsequence then, return 0. 
           return max(solve(str1, str2, index1-1, index2),
           solve(str1, str2, index1, index2-1));
       }
   }
  public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string str1, string str2) {
        // your code here
        int index1 = n;
        int index2 = m;
        
        int LongestCommonSubsequence = solve(str1, str2, index1, index2);
        return LongestCommonSubsequence;
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
   int solve(string str1, string str2, int index1, int index2
    ,vector<vector<int>> & dp){
       
       if(index1 == 0 or index2 == 0){
           return 0;
       }

      // re-use the recusive calls stored value using 0(1) complexity 
       if(dp[index1][index2] != -1){
           return dp[index1][index2];
       }
      
      // there is one common subsequence of both of string return 1,
       if(str1[index1-1] == str2[index2-1]){
           return dp[index1][index2] = 1 + solve(str1, str2, index1-1, index2-1,dp);
       }else{
        //   there is no common subsequence then, return 0. 
           return dp[index1][index2]= max(solve(str1, str2, index1-1, index2,dp),
                                          solve(str1, str2, index1, index2-1,dp));
       }
   }
  public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string str1, string str2) {
        // your code here
        int index1 = n;
        int index2 = m;
        
        // 2D vector for storing the recursive calls
        // Reduce the number of recursive calls
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        
        int LongestCommonSubsequence = solve(str1, str2, index1, index2,dp);
        return LongestCommonSubsequence;
    }
};

/*
3 → DP solution [Tabulation]
  → Create matrix/Array using changeable variables
  → convert the base condition into initialization of DP array/Matrix
  → Copy the recurrence relation [fill using iterative way]
*/

#include <bits/stdc++.h> 

// You have been given two Strings “STR1” and “STR2” of characters. Your task is to find the length of the longest common subsequence.
int getLengthOfLCS(string & str1, string & str2) {
      // Write your code here.
      int n = str1.size();
      int m = str2.size();
      
      // Declare the dp matrix using changable variable 
        int dp[n+1][m+1];

      // base condition convert into instillization of the matrix 
      // intilize first-row and first-com
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j<m+1; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = 0;
                }
            }
        }
            
        // copy the recurrence relation of recursive code    
        //  A common subsequence of two Strings is a subsequence that is common to both Strings.
        //  Got 1 Subsequence, if there are Equal
        //  Else Get the maximum
         for(int i = 1; i < n+1; i++){
            for(int j = 1; j<m+1; j++){
               if(str1[i-1] == str2[j-1]){
                   dp[i][j] = 1 + dp[i-1][j-1];
               }else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
               }
            }
          }
    
    // Print the length of the longest common subsequence. 
        return dp[n][m];
}

/*
4 → DP solution [ Optimizing Space complexity ]
  → If you don't know Space Optimization, you don't know DP.
  → According to the question, do you really need an array or matrix?
  → Either You can just need Last Two value
  → prev_value1 and prev_value2, to Calculate current_value
  → Inorder to remove the extra space complexity
  → we can use DP on space Optimization.
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
          
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m + 1, 0);
        vector<int> cur(m + 1, 0);
         
        for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          // They both are Equal, increase by 1 Else Not matched chars!
            if (text1[i - 1] == text2[j - 1])
                cur[j] = 1 + prev[j - 1]; 
            else
                cur[j] = max(prev[j], cur[j - 1]); 
            }
             prev = cur; 
             // Update the previous row with the current row
        }
        return prev[m];
    }
};