int lcs(string &s1, string &s2){

    // Write your code here.

    int n = s1.size();
    int m = s2.size();
    
    int dp[n+1][m+1];

// instllization of matrix using [first-row and first-col]
	for(int i = 0; i<n+1; i++){
		for(int j = 0; j<m+1; j++){
			if(i == 0 or j == 0){
				dp[i][j] = 0;
			}
		}
	}

// A substring is a continuous segment of a string. For example, "bcd" is a substring of "abcd", while "acd" or "cda" are not.
    int maximum = INT_MIN;
	for(int i = 1; i<n+1; i++){
		for(int j = 1; j<m+1; j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
                maximum = max(dp[i][j],maximum);
			}else{
				dp[i][j] = 0;
			}
		}
	}

    return maximum;
}