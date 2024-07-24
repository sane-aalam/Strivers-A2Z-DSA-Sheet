
// Native Solution 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == nullptr){
            return list2;
        }

        if(list2 == nullptr){
            return list1;
        }
        
		// store all node values in a vector
        vector<int> v;
        ListNode *p = list1;

        while(p){
            v.push_back(p->val);
            p = p->next;
        }

        ListNode *q = list2;

        while(q){
            v.push_back(q->val);
            q = q->next;
        }

		// sort the vector
        sort(v.begin(), v.end());
		// make a new linkedlist from the vector
        reverse(v.begin(), v.end());
        ListNode *a = new ListNode(v.back());
        ListNode *b = a;
        v.pop_back();
        while(!v.empty()){
            b->next = new ListNode(v.back());
            v.pop_back();
            b = b->next;
        }
        return a;
        
    }
};


// Better Solution 

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int> * t1 = first;
    Node<int> * t2 = second;
    Node<int> * dummyNode = new Node<int>(-1);
    Node<int> * temp = dummyNode;

    // Two pointer Algorithm - (MERGE SORTED ARRAY LOGIC SAME TO SAME) 
    while(t1 != nullptr && t2 != nullptr){
        if(t1->data < t2->data){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }

   // case-1 Linked List (first) is remaning to connect with new list linked Node
   // case-2 second Linked List is remaning to connect with new list linked Node 
   // return dummyNode(-1) -> actualNode(1)
   // return dummyNode->nextNode 

    if(t1 != nullptr){
        temp->next = t1;
    }else{
        temp->next = t2;
    }
    return dummyNode->next;
}

