#include <bits/stdc++.h> 
string shortestSupersequence(string str1, string str2)
{
	// Write your code here.
	 // size of the str1,str2
        int n = str1.size();
        int m = str2.size();
        
        // create the matrix using changable variables
        int dp[n+1][m+1];
        // Initialization [base condition convert into the initialization first row,first column]
        for(int i= 0; i< n+1; i++){
            for(int j = 0; j< m+1; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        
        // fill the matrix using [convert the recurrence relation into iterative way]
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        
   // case-2 store the shortest common subsequence into the string 
        string result = "";
        int i = n;
        int j = m;
        
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                result.push_back(str1[i-1]);
                i--;
                j--;
            }else{
                if(dp[i][j-1] > dp[i-1][j]){
                    result.push_back(str2[j-1]);
                    j--;
                }else{
                    result.push_back(str1[i-1]);
                    i--;
                }
            }
        }

    // by chance anyone of string empty 
        // we can store only first string 
        while(i > 0){
                result.push_back(str1[i-1]);
                   i--;
         }

         // by chance anyone of string empty 
        // we can store only second string
           while(j > 0){
                result.push_back(str2[j-1]);
                   j--;
        }

   // case-3 reverse the result string to get correct form output 
      reverse(result.begin(), result.end());
      return result;
}