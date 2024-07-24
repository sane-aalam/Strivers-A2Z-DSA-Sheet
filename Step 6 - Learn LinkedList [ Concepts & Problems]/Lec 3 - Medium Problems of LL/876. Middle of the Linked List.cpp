/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    // Write your code here
    Node * slow = head;
    Node * fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
        if(fast->next != nullptr){
              fast = fast->next;
        }
    }
    return slow;
}

// leetcode solution - 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * slow_pointer = head;
        ListNode * fast_pointer = head;

        while(fast_pointer != nullptr && fast_pointer->next != nullptr){
            slow_pointer = slow_pointer->next;
            fast_pointer = fast_pointer->next;
            if(fast_pointer->next != nullptr){
                fast_pointer = fast_pointer->next;
            }
        }
        return slow_pointer;
    }
};