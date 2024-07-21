


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // 1 - create the adjecency list 
        int V = numCourses;
        vector<int> adj[V];
        for(auto it : prerequisites){
            // There are a total of 2 courses to take. 
            // To take course 1 you should have finished course 0. \
            // So it is possible.

            // simple i can understand ( 1 comes before 0)
	        adj[it[1]].push_back(it[0]);
	    }
        
        // 2 - create the indegree part of the perfoming the algortim kan's algortim 
        vector<int> indegree(V,0);
        for(int i = 0; i<V; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        // 3 - inorder to perfrom kadn's algo, we need queue and vector array 
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        // 4 - perfom the main task pop the node and push into the answer 
        // but we can use counter, now we are using answer array
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);
            for(auto it : adj[node]){
                indegree[it] --;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        // Return true if you can finish all courses - means you are able to store all nodes 
        if(ans.size() == V){
            return true;
        }
        // Otherwise, return false. - you are not able to fisish all coursed
        return false;
    }
};













