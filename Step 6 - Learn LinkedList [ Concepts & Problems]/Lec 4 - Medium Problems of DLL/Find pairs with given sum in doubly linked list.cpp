/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/

// 1. You are given a sorted doubly linked list of size 'n', consisting of distinct
// positive integers, and a number 'k'.
// 2. because given sorted doubly linked List, Can we think about Two pointer Algorithm 


vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.

     /* Initialize start and end pointers */
    Node * start = head;
    Node * end = head;
    while(end->next!= nullptr){
        end = end->next;
    }

    int targetValue = k;
    vector<pair<int,int>> result;

// You are given a sorted doubly linked list of size 'n', consisting of distinct positive integers, and a number 'k'.
// sorted array take use to Two pointer Algorithm
    while(start < end){
        int x = start->data;
        int y = end->data;
        int TwoSum = x + y;
        if(TwoSum == targetValue){
            pair<int,int> p;
            p.first = x;
            p.second = y;
            result.push_back(p);
            start = start->next;
            end = end->prev;
        }else if(TwoSum < targetValue){
            start = start->next;
        }else{
            end = end->prev;
        }
    }
    return result;
}

