/*
1 → DP solution [ Using Recursion ]
  → Express Everything in terms of index
  → Do all the stuff on that index
  → According to question [find min, max, sum-up,longest, shortest,total number of ways]
*/

/*
2 → DP solution [memorization]
  → Identification of overlapping problems
  → Reduce the overlapping recursive calls
  → Create Array/Matrix using changeable variables
  → Store the recursive calls
  → Re-use the recursive calls
*/

/*
3 → DP solution [Tabulation]
  → Create matrix/Array using changeable variables
  → convert the base condition into initialization of DP array/Matrix
  → Copy the recurrence relation [fill using iterative way]
*/

/*
4 → DP solution [ Optimizing Space complexity ]
  → If you don't know Space Optimization, you don't know DP.
  → According to the question, do you really need an array or matrix?
  → Either You can just need Last Two value
  → prev_value1 and prev_value2, to Calculate current_value
  → Inorder to remove the extra space complexity
  → we can use DP on space Optimization.
*/

#include <bits/stdc++.h> 

int longestCommonSubsequence(string str1, string str2){
	int n = str1.size();
	int m = str2.size();
	int dp[n+1][m+1];
	for(int i = 0; i<n+1; i++){
		for(int j = 0; j<m+1; j++){
			if(i == 0 or j == 0){
				dp[i][j] = 0;
			}else if(str1[i-1] == str2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else if(str1[i-1] != str2[j-1]){
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}

int minCharsforPalindrome(string str){
	// Write your code here
	string str1 = str;
	string str2 = str;
	reverse(str2.begin(),str2.end());
	int LPS = longestCommonSubsequence(str1,str2);
	int n  = str.size();
	return n - LPS;
}