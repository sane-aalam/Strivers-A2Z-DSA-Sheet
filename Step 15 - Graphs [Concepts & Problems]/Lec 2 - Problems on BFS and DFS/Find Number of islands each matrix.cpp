// step-1 create the grid matrix using oprations
// step-2 apply the concept number of islands 
// step-3 store the each  matrix creation for matrix

class Solution {
 public:
  int BFSAlgorithm(int row, int col, vector<vector<int>> & grid, vector<vector<int>> & visitedMatrix ){
      
 // size of the matrix (row-wise and col-wise)
    int n = grid.size();
    int m = grid[0].size();
    
      queue<pair<int,int>> q;
      q.push({row,col});
      visitedMatrix[row][col] = 1;
      
      while(!q.empty()){
          int row = q.front().first;
          int col = q.front().second;
          q.pop();
    
    // connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
        //   int delrow[8] = {-1,1,0,0,-1,1,-1,1};
        //   int delcol[8] = {0,0,-1,1,1,-1,-1,1};
            
         int delrow[4] = {-1,0,1,0};
         int delcol[4] = {0,1,0,-1};
        
          for(int direction = 0; direction < 4; direction ++){
              int newrow = row + delrow[direction];
              int newcol = col + delcol[direction];
    
    // Matrix valid range + not already visited current cell + current cell have land (1)
    // all condition is valid Then push into the queue and mark visited 
    // you should do clear dry run 
    // you can also try 4-direction and 8-direction 
              if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m 
               && visitedMatrix[newrow][newcol] == 0 && grid[newrow][newcol] == 1){
                   q.push({newrow,newcol});
                   visitedMatrix[newrow][newcol] = 1;
               }
          }
      }
  }
  
// Function -> find the number of island every matirx [each you have created]
    int numIslandsCount(vector<vector<int>>& grid,vector<vector<int>> & visitedMatrix, int a, int b) {
        // Code here
        
    // size of the matrix (row-wise and col-wise)
        int n = grid.size();
        int m = grid[0].size();
        
    // Count the number of islands
    // Traversal Algorithm Design in such manner, They will cover all connected nodes easy 
        int NumberOfIslands = 0;
        
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
            // if current cell are Land and not alredy visited
                if(grid[row][col] == 1 && visitedMatrix[row][col] == 0){
                    BFSAlgorithm(row,col,grid,visitedMatrix);
                    NumberOfIslands ++;
                }
            }
        }
        return NumberOfIslands;
    }

// main function
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<int> result;
        
         vector<vector<int>> grid(n,vector<int> (m));
        
        // grid creation using 
        // gird[0][1] = 0,1,0,1
        for(auto it : operators){
            grid[it[0]][it[1]] = 1;
             vector<vector<int>> visitedMatrix(n,vector<int> (m,0));
             result.push_back(numIslandsCount(grid,visitedMatrix,n,m));
        }
        return result;
    }
};
