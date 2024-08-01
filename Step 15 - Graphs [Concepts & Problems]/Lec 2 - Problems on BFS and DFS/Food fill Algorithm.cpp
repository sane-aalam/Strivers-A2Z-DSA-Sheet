#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, 
int n, int m, int x, int y, int p) {
    // Write your code here.

    int N = n;
    int M = m;
    int startrow = x;
    int startcol = y;
    int newColor = p;

    vector<vector<int>> vis(N,vector<int>(M,0));
    queue<pair<int,int>> q;

    int startcolor = image[x][y];

    q.push({startrow,startcol});
    vis[startrow][startcol] = 1;
    image[startrow][startcol] = newColor;

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // Traversal the matrix 4-direction
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        for(int direction = 0; direction < 4; direction++){
            int newrow = delrow[direction] + row;
            int newcol = delcol[direction] + col;

            if(newrow >= 0 && newrow < N && newcol >= 0 && newcol < M 
             && image[newrow][newcol] == startcolor && vis[newrow][newcol] == 0 ){
                 q.push({newrow,newcol});
                 vis[newrow][newcol] = 1;
                 image[newrow][newcol] = newColor;
             }
        }
        
    }
    return image;
}