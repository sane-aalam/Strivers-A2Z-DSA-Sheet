class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int> inDegree(V);
	    
	    // store the all inDgree into the array
	    for(int i = 0; i<V; i++){
	        for(auto it : adj[i]){
	            inDegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    for(int node = 0; node < V; node++){
	        if(inDegree[node] == 0){
	            q.push(node);
	        }
	    }
	    
	    int count = 0;
	    
	    while(!q.empty()){
	        int node = q.front(); q.pop();
	        
	        count ++;
	        for(auto it : adj[node]){
	            // reduce the indegree,push into the queue Those have indegree Zero
	             inDegree[it]--;
	             if(inDegree[it] == 0){
	                 q.push(it);
	             }
	        }
	    }
	    
	    if(count == V){
	        return false;
	    }else{
	        return true;
	    }
    }
};