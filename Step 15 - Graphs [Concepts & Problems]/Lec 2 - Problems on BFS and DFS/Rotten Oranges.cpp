
#include <queue>
#include <vector>

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
       // Write your code here. 
        // int n = grid.size();
        // int m = grid[0].size();

        // create queue using pair concept 
        queue<pair<pair<int,int>,int>> q;

        // data is important,so don't change original data
        vector<vector<int>> visted = grid;

        for(int row = 0; row < n ; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == 2){
                    q.push({{row,col},0});
                    visted[row][col] = 2;
                }
            }
        }

        // any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
        int delrow[4] = {-1,0,1,0}; 
        int delcol[4] = {0,1,0,-1};

        int minimumTime = 0;

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();

            // calculate the rootern orgrans minimul time 
            minimumTime = max(time,minimumTime);

            for(int index = 0; index < 4; index++){
                int newrow = row + delrow[index];
                int newcol = col + delcol[index];

                //valid range + a fresh orange + not alredy rottern
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m 
                   && grid[newrow][newcol] == 1 && visted[newrow][newcol] != 2
                ){
                    q.push({{newrow,newcol},time+1});
                    visted[newrow][newcol] = 2;
                }
            }    


        }
            // case - 03 AGAR KOI CELL ME FRESH ORANGE HAI TOH DIRECLY RETURN -1
            // no cell has a fresh orange
            // return -1
            for(int i=0;i<n;i++ ){
                for(int j=0;j<m;j++) {
                    if(visted[i][j]==1){
                        return -1;
                    }
                }
        }
        return minimumTime;
}