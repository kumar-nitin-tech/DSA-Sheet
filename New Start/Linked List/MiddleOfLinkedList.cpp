/*
    Find middle element in a Linked List

    Problem Statement:  Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

    Problem Link:   https://www.codingninjas.com/studio/problems/973250?topList=striver-sde-sheet-problems
                    https://leetcode.com/problems/middle-of-the-linked-list/

    Refer:  https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/

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

//Naive Approach
//TC:   O(N + N/2)
//SC:   O(1)
Node* middleLinkedListNodeBrute(Node* &head){
    //We have to find the len of the linked list first;
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp ->next;
        len++;
    }
    int mid = len/2;
    for(int i=1; i<=mid; i++){
        head = head->next;
    }
    return head;
}

//Optimal Approach
//TC:
//SC:
Node* middleLinkedListNodeOptimal(Node* &head){
    //We keep two pointer one slow and another fast 
    Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    Node* head = NULL;
    linkedListClass list;
    for(auto i:arr)
        list.insert(i,head);

    Node* middleNode = middleLinkedListNodeOptimal(head);

    list.printList(middleNode);

    return 0;
}