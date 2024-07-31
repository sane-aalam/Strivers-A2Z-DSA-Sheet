class Solution
{
    private:
    // Function to find the length of longest common subsequence in two strings.
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
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        int lcs_length = longestCommonSubsequence(X,Y);
        int first_length = m;
        int second_length = n;
        
        int result = first_length + second_length - lcs_length;
        return result;
    }
};
