/*
    Merge two sorted Linked Lists
    Problem Statement:  Given two singly linked lists that are sorted in increasing order of node values, merge two sorted linked lists and return them as a sorted list. The 
                        list should be made by splicing together the nodes of the first two lists.

    Problem Link:   https://leetcode.com/problems/merge-two-sorted-lists/
                    https://www.codingninjas.com/studio/problems/800332?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/merge-two-sorted-linked-lists/

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

//Merge Two Sorted Linked List
//Brute Approach
//TC:  O(N+M) 
//SC:   O(N+M)
Node* mergeSortedLinkedListBrute(Node* head1, Node* head2){
    //We are creating a new linked list to stoe the sorted linked list
    Node* newHead = new Node(0);
    Node* dummyNode = newHead;
    Node* temp1 = head1, *temp2 = head2;
    while(temp1 && temp2){
        if(temp1->data < temp2->data){
            dummyNode->next = temp1;
            temp1 = temp1->next;
            dummyNode = dummyNode->next;
        }   
        else{
            dummyNode ->next = temp2;
            temp2 = temp2->next;
            dummyNode = dummyNode->next;
        } 
    }
    
    while(temp1){
        dummyNode ->next = temp1;
        temp1 = temp1->next;
        dummyNode = dummyNode->next;
    }
    
    while(temp2){
        dummyNode->next = temp2;
        temp2 = temp2->next;
        dummyNode = dummyNode->next;
    }
    return newHead->next;
}

//Optimal Approach
//TC: O(N+M)
//SC: O(1)
Node* mergeSortedLinkedListOptimal(Node *l1, Node *l2){
    if(l1 == NULL)  return l2;
    if(l2 == NULL)  return l1;
    if(l1->data > l2->data) swap(l1,l2);
    Node* res = l1;
    while(l1 != NULL && l2 != NULL){
        Node* temp = NULL;
        while(l1 != NULL && l1->data <= l2->data){
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        swap(l1,l2);
    }
    return res;
}



int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr1(n), arr2(m);
    for(auto &i:arr1)    cin>>i;
    for(auto &i:arr2)    cin>>i;
    Node* head1 = NULL, *head2 = NULL;
    linkedListClass list;
    for(auto i:arr1)    list.insert(i,head1);
    for(auto i:arr2)    list.insert(i,head2);

    Node* mergeNode = mergeSortedLinkedListOptimal(head1, head2);
    list.printList(mergeNode);
    return 0;
}