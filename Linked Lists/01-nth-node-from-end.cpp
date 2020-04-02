/*

-----------------------------------------------------------------
Problem: Finding the nth node from the end of a linked list.
-----------------------------------------------------------------

Reframe: We need to find the nth node from the last of a linked list

Possible Testcases:
What to do incase of an empty list? What if list has only one element? What if "n" is larger than the length of the list?

list = 1 2 3 4 5 , n = 4
output = 2

The thought process:

We can reverse the linked list? Then the problem will be just to find the nth node from start!
Lets get started!
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
-----------------------------------------------------------
Starter code for insertion and print of linked list.
-----------------------------------------------------------
*/

struct Node{
    int data;
    Node *next;
};

Node *insert(Node *root, int data){
    if(!root){
        return NULL;
    }

    Node *temp = root;
    Node *newNode = new Node();
    newNode->next = NULL;
    newNode->data = data;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;

    return root;
}

void *printList(Node *root){
    while(root != NULL){
        cout<<root->data<<" ";
        root = root->next;
    }
    cout<<endl;
}

Node *reverse(Node *root){
    Node *current = root;
    Node *prev = NULL;
    Node *next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
      

int main(){
    /*
    Lets make a linked list first
    Eg: 100->200->250->300->400->NULL
    */

    Node *root = new Node();
    root->next = NULL;
    root->data = 100;
    root = insert(root, 200);
    root = insert(root, 250);
    root = insert(root, 300);
    root = insert(root, 400);

    cout<<"Enter n"<<endl;
    int n;
    cin>>n;

    // Problem is to find the nth node from the end

    /*
    ----------------------------------------------------
    Approach 1: Reverse the linked list and then print the nth element
    ----------------------------------------------------
    */
    root = reverse(root);
    // now root has the reversed linked list, all we need to do is to print the nth node

    Node *temp = root;
    int count = 0;

    while((count != n-1) && (temp != NULL)){
        count++;
        temp = temp->next;
    }
    // This outputs the nth node from the end
    // cout<<temp->data<<endl;

    /*
    ----------------------------------------------------
    Approach 2: Find the length of the linked list, and then print the (len - n)th node
    ----------------------------------------------------
    */

    //resetting the linked list
    root = reverse(root);

    count = 0;
    temp = root;

    while(temp != NULL){
        temp = temp->next;
        count++;
    }

    // now count stores the length of the linked list, all we have to do is print the (len - n) element

    temp = root;
    int itr = 0;
    while(itr != (count - n)){
        temp = temp->next;
        itr++;
    }

    // cout<<temp->data<<endl;

    /*
    ----------------------------------------------------
    Approach 3: (Tricky) Make two pointers, and start moving the slow pointer after the fast pointer has moved n steps! (Trace it out)
    Eg: 100 200 250 300 400
    n = 2

    fastPtr = 100 -> 200 -> 300 -> 400 -> 500
    slowPtr = 100 -> 200

    the slowPtr moves only after the fastPtr has moved n steps! And it gives us the nth node from the end.
    ----------------------------------------------------
    */

    Node *slowPtr = root;
    Node *fastPtr = root;

    count = 0;
    //moving the fastPtr by n steps
    while(count < n){
        fastPtr = fastPtr->next;
        count++;
    }

    // now moving both the pointers together till the end of the list to get the nth node from the end!

    while((fastPtr != NULL) && (slowPtr != NULL)){
        fastPtr = fastPtr->next;
        slowPtr = slowPtr->next;
    }

    cout<<slowPtr->data<<endl;

    /*
        Now evaluating all the three approaches.
        Approach 1 and Approach 2 involves the traversal of list more than once.
        We reverse the list in approach 1 and then traverse till we reach end. In the worst case scenario, we might have to traverse the list twice ( if n == size of the list). Similar thing happens in Approach 2 as well.

        Approach 3 solves the problem in a single iteration of the linked list!
    */

}