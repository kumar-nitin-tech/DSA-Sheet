/*
    Rotate a Linked List

    Problem Statement:  Given the head of a linked list, rotate the list to the right by k places.  

    Problem Link:   https://leetcode.com/problems/rotate-list/description/
                    https://www.codingninjas.com/studio/problems/920454?topList=striver-sde-sheet-problems&leftPanelTabValue=PROBLEM
    Refer:  https://takeuforward.org/data-structure/rotate-a-linked-list/

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
        Node(){
            data = 0;
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

//Brute force
//TC: (n*k)
//SC: O(1)
Node* rotateLinkedListBrute(Node* head, int k){
    //Brute force idea is to move every last node to head for k time
    for(int i=0; i<k; i++){
        Node* temp = head;
        while(temp->next->next) temp = temp->next;
        Node* end = temp->next;
        temp->next = NULL;
        end->next = head;
        head=  end;
    }
    return head;
}

//Optimal Approach
//TC: O(N) + O(N - k)
//SC:   O(1)
Node* rotateLinkedList(Node* head, int k){
    int len = 1;
    Node* temp = head;
    while(temp->next){
        len++;
        temp = temp->next;
    }
    k = k%len;
    int diff = len - k;
    temp->next = head;

    while(diff--){
        temp = temp->next;
    }
    head = temp ->next;
    temp->next = NULL;
    return head;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    Node* head = NULL;
    linkedListClass list;
    for(auto i:arr)	list.insert(i,head);
    Node* ans = rotateLinkedList(head,k);
    list.printList(ans);
    return 0;
}