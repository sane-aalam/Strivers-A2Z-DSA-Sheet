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
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.

    if(head != nullptr and head->next == nullptr){
        return true;
    }

    stack<int> st;
    LinkedListNode<int> * temp = head;

    while(temp != nullptr){
        int data = temp->data;
        st.push(data);
        temp = temp->next;
    }

    temp = head;

    while(temp != nullptr){
        int stakElement = st.top();
        int nodevalue = temp->data;
        if(stakElement != nodevalue){
            return false;
        }
        st.pop();
        temp = temp->next;
    }
    return true;
}