class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        
      // size of the strings
        int n = s.size();
        int m = t.size();
        
      // create the matrix using sizes
        int dp[n+1][m+1];
      
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j<m+1; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = i+j;
                }
            }
        }
     
    // According to question Given hay!
    // The possible operations are permitted:   
    // option-1 Insert a character at any position of the string.
    // option-2 Remove any character from the string.
    // option-3 Replace any character from the string with any other character.
        
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j<m+1; j++){
               if(s[i-1] == t[j-1]){
                   dp[i][j] = dp[i-1][j-1];
               }else{
                   int insert = 1 + dp[i-1][j];
                   int remove = 1 + dp[i][j-1];
                   int replace = 1 + dp[i-1][j-1];
                   dp[i][j] = min(insert,min(remove,replace));
               }
            }
        }
        return dp[n][m];
    }
};