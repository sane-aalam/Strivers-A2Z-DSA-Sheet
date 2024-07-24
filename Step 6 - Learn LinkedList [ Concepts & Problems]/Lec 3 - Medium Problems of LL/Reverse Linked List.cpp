#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

// 1. pick the current Node
// 2. connect with prevNode 
// 3. make sure,When you are connecting with prevNode, don't lose next linked List 


LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int> * currentNode = head;
    LinkedListNode<int> * prevNode  = NULL;
    LinkedListNode<int> * frontNode = NULL;

    while(currentNode != nullptr){
        frontNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = frontNode;
    }
    head = prevNode;
    return head;
}
