class Solution {
     private:
  void DFSAlgorithm(int node, vector<int> & visitedArray, 
  vector<int> & DFSTraversal, vector<int> adj[]){
      
      // Mark visited + store into the result array
      // Explore the adjacency list
      
      DFSTraversal.push_back(node);
      visitedArray[node] = 1;
      
      for(auto adjNode : adj[node]){
          if(visitedArray[adjNode] == 0){
              DFSAlgorithm(adjNode, visitedArray, DFSTraversal, adj);
          }
      }
  }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> DFSTraversal;
        vector<int> visitedArray(V,0);
        
        for(int node = 0; node < V; node++){
    
    // currentNode is not already visited 
    // Then We have to call DFS algorithm for current node 
    // starting from the 0th vertex from left to right according to the graph.
    // make sure, you should have to carry the visited array 
    // relax your mind + body
            if(visitedArray[node] == 0){
                DFSAlgorithm(node,visitedArray,DFSTraversal,adj);
            }
        }
        return DFSTraversal;
    }
};