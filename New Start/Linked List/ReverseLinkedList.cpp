/*
    Reverse a Linked List

    Problem Statement:  Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.  

    Problem Link:   https://www.codingninjas.com/studio/problems/799897?topList=striver-sde-sheet-problems
                    https://leetcode.com/problems/reverse-linked-list/

    Refer:  https://takeuforward.org/data-structure/reverse-a-linked-list/

*/

#include<bits/stdc++.h>
using namespace std;

//Structure of Linked List
class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }
};

//Input Of Linked List
class linkedListClass{
    public:
        void insert(int val, Node* &head){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                return;
            }
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }

        void printList(Node* head){
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
};

//Reverse the Linked List
//Iterative method
//TC:   O(N)
//SC:   O(1)
Node* reverseLinkedList(Node* &head){
    //Idea is to use 3 pointer
    if(head == NULL){
        return NULL;
    }
    Node *prev, *nextPtr;
    prev = NULL;
    nextPtr = head->next;

    while(head != NULL){
        nextPtr = head->next;
        head->next = prev;
        prev = head;
        head = nextPtr;
    }
    return prev;
}

//Recursive Method
//TC: O(N)
//SC: O(N)
Node* reverseLinkedListR(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newHead = reverseLinkedListR(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    Node* head = NULL;
    linkedListClass list;
    for(auto i:arr){
        list.insert(i,head);
    }
    //list.printList(head);

    Node* root = reverseLinkedListR(head);

    list.printList(root);
    return 0;
}