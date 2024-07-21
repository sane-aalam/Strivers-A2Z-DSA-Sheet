




class Solution{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	      // create inDgree Array/Vector for storing the inDgree 
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
	    
	    vector<int> resultArray;
	    
	    while(!q.empty()){
	        int node = q.front(); q.pop();
	        
	        resultArray.push_back(node);
	        for(auto it : adj[node]){
	            // reduce the indegree,push into the queue Those have indegree Zero
	             inDegree[it]--;
	             if(inDegree[it] == 0){
	                 q.push(it);
	             }
	        }
	    }
	   return resultArray; 
	}
};