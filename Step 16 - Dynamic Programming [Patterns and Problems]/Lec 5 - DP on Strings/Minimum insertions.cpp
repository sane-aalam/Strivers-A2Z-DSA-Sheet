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