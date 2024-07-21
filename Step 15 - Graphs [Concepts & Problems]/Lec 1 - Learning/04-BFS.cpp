#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
    // Inorder to perfrom BFS Algorithm, we need queue dsa, array visited, array for storing the resullt-Data 
        vector<int> resultArray;
        vector<int> visitedArray(V,0);
        queue<int> queueDSA;
        
    // The task is to do Breadth First Traversal of this graph starting from 0.
    // First node is to be mark visited for not-coming again same node
    
        queueDSA.push(0);
        visitedArray[0] = 1;
    
    // Perform BFS algorithm 
        while(!queueDSA.empty()){
           int node = queueDSA.front();
           queueDSA.pop();
    
    // BFS traversal of the graph starting from the 0th vertex from left to right.
    // Store into the result-array everyNodes
    
           resultArray.push_back(node);
           //  adjacency list as input parameters
           // When you popped the nodes,Then go to adj-list,checkout the currentNode is visited or not 
           // if current node (adjlist node) is visited alredy no need push into queue
           // if current node is not visited , we have to push into queue and mark visited for future calls
           for(auto connectedNodes : adj[node]){
               if(visitedArray[connectedNodes] == 0){
                   queueDSA.push(connectedNodes);
                     visitedArray[connectedNodes] = 1;
               }
           }
        }
        
        // return the result array 
        return resultArray;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}