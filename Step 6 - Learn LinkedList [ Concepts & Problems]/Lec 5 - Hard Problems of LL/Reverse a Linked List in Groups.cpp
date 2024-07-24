/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        
        // Complete this method
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        struct node *prev = NULL;
        struct node *fast = NULL;
        struct node *curr = head;
        // count for making sure size less than K 
        int count = 0;
        
        while(curr != NULL && count < k){
            fast = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fast;
            count++;
        }
        
        // recursively reverse k-size linked list node
        // GFG solution- easy to understand 
        // Simple and clear Node
        if(fast != NULL){
            head->next = reverse(fast,k);
        }
        
        head = prev;
        return head;
        
    }
};