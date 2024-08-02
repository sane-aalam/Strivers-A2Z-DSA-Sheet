
/*
➜ Problem statement : 
You have been given a 2-D array 'mat' of size 'M x N' where 'M' and 'N' denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order.

➜ Approach 
  1. start with lastCell to check currentCell have target 
  2. sorted in non-decreasing order, takes advatage, reduce the search-space 
  3. until you have't got the target!
*/

bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();

        int startIndex = 0;
        int endIndex = m - 1;

        while(startIndex >= 0 && startIndex < n && endIndex >= 0 && endIndex < m){
            if(mat[startIndex][endIndex] == target){
                return 1;
            }else if(mat[startIndex][endIndex] < target){
                startIndex++;
            }else{
                endIndex--;
            }
        } 
        return 0;
}