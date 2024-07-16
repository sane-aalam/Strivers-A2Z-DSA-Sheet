class Solution{
    
    public:
   
    Node* reverseDLL(Node * head){
        
        Node* temp = head;
        stack<int> st;
        while(temp){
            st.push(temp->data);
            temp = temp->next;
        }
        
        temp = head;
        while(!st.empty()){
            
            temp->data = st.top(); st.pop();
            temp = temp->next;
        }
        
        return head;
        
    }
};