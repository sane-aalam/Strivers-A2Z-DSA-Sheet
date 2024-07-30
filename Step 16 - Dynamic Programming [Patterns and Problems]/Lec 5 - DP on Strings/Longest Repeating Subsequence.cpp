#include <bits/stdc++.h>


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
            
       //we will not match A at index 0 to A at index 0
  //since we are trying to find repeating, we want to find duplicate elements at different index
         for(int i = 1; i < n+1; i++){
            for(int j = 1; j<m+1; j++){

  // just make sure (i != j)
  // we ensure that element at the same index is not included
               if(str1[i-1] == str2[j-1] && i != j){
                   dp[i][j] = 1 + dp[i-1][j-1];
               }else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
               }
            }
          }
    
    // Print the length of the longest common subsequence. 
       return dp[n][m];
} 
int longestRepeatingSubsequence(string st, int n)
{
	// Write your code here
	return getLengthOfLCS(st,st);
}

