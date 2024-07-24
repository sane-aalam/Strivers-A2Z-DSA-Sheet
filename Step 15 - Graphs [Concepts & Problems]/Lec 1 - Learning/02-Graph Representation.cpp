class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        
        vector<vector<int>> adj(V);
        
        // we have to iterate the edeges
        for(auto it : edges){
            int firstNode = it.first;
            int secondNode = it.second;
            
            adj[firstNode].push_back(secondNode);
            adj[secondNode].push_back(firstNode);
        }
        return adj;
    }
};