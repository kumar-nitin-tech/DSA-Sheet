/*
    Flattening a Linked List

    Problem Statement:  Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
                        (i) a next pointer to the next node,
                        (ii) a bottom pointer to a linked list where this node is head.
                        Each of the sub-linked-list is in sorted order.
                        Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
                        Note: The flattened list will be printed using the bottom pointer instead of the next pointer.

    Problem Link:   https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
                    https://www.codingninjas.com/studio/problems/1112655?topList=striver-sde-sheet-problems&leftPanelTabValue=PROBLEM

    Refer:  https://takeuforward.org/data-structure/flattening-a-linked-list/

*/

#include<bits/stdc++.h>
using namespace std;

//Structure of Linked List
class Node{
    public:
        int data;
        Node* next, *bottom;

        Node(int val){
            data = val;
            next = NULL;
            bottom = NULL;
        }
        Node(){
            data = 0;
            next = NULL;
            bottom = NULL;
        }
};

//Approach
//TC: O(N) N-> all nodes present in the all linked list including bottom and next
//SC: O(1)

Node* merge(Node* a, Node* b){
    //we have to check the bottom of the node head in sorted manner by checking data of the node
    //dummy node for the iteration and returing the node
    Node* temp = new Node(), *dummy = temp;

    while(a!=NULL && b!=NULL){
        if(a->data > b->data){
            temp->bottom = b;
            b = b->bottom;
            temp = temp->bottom;
        }
        else {
            temp->bottom = a;
            a = a->bottom;
            temp = temp->bottom;
        }
    }
    if(a!= NULL){
        temp->bottom = a;
    }
    else if(b!= NULL){
        temp->bottom = b;
    }
    return dummy->bottom;
}

Node* flatten(Node* head){
    //We have to reach the last node 
    if(head == NULL || head->next == NULL){
        return head;
    }
    //move to the next node head of linked list
    head->next = flatten(head->next);

    //now we have to merge the last two head node
    head = merge(head, head->next);

    return head;
}

int main(){
    Node *head = new Node(5);
    head->bottom = new Node(8);
    head->bottom->bottom = new Node(30);
    head->next = new Node(10);
    head->next->bottom = new Node(20);
    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    Node* ans = flatten(head);

    while(ans!= NULL){
        cout<<ans->data<<" ";
        ans = ans->bottom;
    }
    return 0;
}