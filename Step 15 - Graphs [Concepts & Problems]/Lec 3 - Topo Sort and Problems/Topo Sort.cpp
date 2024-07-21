#include <stack>
#include <vector>

// Those Who have completed the their recursive DFS calls, push into the stack
class Solution{  
    private:
    void DFSAlgorithm(int node, vector<int> & visitedArray, stack<int> & st, vector<int> adj[]){
      
      // Explore the adjacency list
      visitedArray[node] = 1;
      
      for(auto adjNode : adj[node]){
          if(visitedArray[adjNode] == 0){
              DFSAlgorithm(adjNode, visitedArray, st, adj);
          }
      }
      st.push(node);
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> st;
	    vector<int> visited(V,0);
	    
	    for(int node = 0; node < V; node++){
	        if(visited[node] == 0){
	            DFSAlgorithm(node,visited,st,adj);
	        }
	    }
	    
	    vector<int> resultArray;
	    
	    while(!st.empty()){
	        int node = st.top();
	        resultArray.push_back(node);
	        st.pop();
	    }
	    
	    return resultArray;
	}
};