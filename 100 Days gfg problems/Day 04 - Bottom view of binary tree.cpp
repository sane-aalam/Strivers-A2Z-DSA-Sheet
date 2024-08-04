
// binary Tree - view patterns
// map <int,int> mp
// map<-1,1> mp
// move to direction left to decrease by 1
// move to direction right to increase by 1 

class Solution {
  public:
    vector <int> bottomView(Node *root) {
    
     vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        map <int, int> mapping;
        queue<pair<Node*, int >> q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
        
                // upper say aate jao jiske mapping stroe hay jis index wo automatic
                // upper say niche aaate filter ho jaygei 
                // finally result clear aayaga
                mapping[hd] = frontNode->data;
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
      }
      
      for(auto i:mapping){
          ans.push_back(i.second);
      }
      return ans;   
    }
};