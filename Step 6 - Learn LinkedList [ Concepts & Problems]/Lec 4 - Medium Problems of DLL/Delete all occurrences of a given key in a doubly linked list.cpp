/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        
       struct Node* head = *head_ref;
       
       // if First is Key
       // If last is key
       // If Middle is key
       
     // case-1 When you head node is delete in doubly linked list 
       while(head != nullptr){
           if(head->data == x){
               if(head->prev == nullptr){
                   *head_ref = head->next;
                   if(head->next != nullptr){
                       head->next->prev = nullptr;
                   }
               }
                // When last node is deleted in double linked
               else if(head->next == nullptr){
                   head->prev->next = nullptr;
                // When deleted node is middle 
                // Then pointer chnaged concept here 
               }else{
                   head->next->prev = head->prev;
                   head->prev->next = head->next;
               }
           }
         // incease the head for next node 
           head = head->next;
       }
    }
};


