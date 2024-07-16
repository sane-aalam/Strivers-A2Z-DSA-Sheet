// Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 

//Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{
   // Your code here
   // Indentify the inserted point
   // case-1 it can be end of the linked list
   // case-2 it can be middle (between ) of two nodes
   
   Node * temp = head;
   Node * newNode = new Node(data);
   
  // (0-based indexing) - according to question 
   for(int i = 0; i<pos; i++){
       temp = temp->next;
   }
   
   // When you have reached the nullpter, means you have to inserted into the last of the linked list
   if(temp->next == nullptr){
       temp->next = newNode;
       newNode->prev = temp;
       // last node connect with nullptr
       newNode->next = nullptr;
   }else{
     // pointer interchanging methods
       newNode->prev = temp;
       newNode->next = temp->next;
       temp->next->prev = newNode;
       temp->next = newNode;
   }
   
}