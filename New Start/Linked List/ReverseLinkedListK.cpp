/*
    Reverse Linked List in groups of Size K

    Problem Statement:  Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list. k is a positive integer and is less than or 
                        equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

    Problem Link:   https://leetcode.com/problems/reverse-nodes-in-k-group/
                    https://www.codingninjas.com/studio/problems/763406?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/reverse-linked-list-in-groups-of-size-k/

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

//approach
//TC: O(N)
//SC:  O(1)
Node* reverseKLinkedList(Node* &head, int k){
    //First we have to find the len of the linked list
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prev = dummy, *curr, *nex;
    while(k<=len){
        curr = prev->next;
        nex = curr->next;
        //as it takes k-1 operation to reverse the k size linked list
        for(int i=0; i<k-1; i++){
            curr->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
            nex = curr->next;
        }
        prev = curr;
        len -= k;
    }

    return dummy->next;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    Node* head = NULL;
    linkedListClass list;
    for(auto i:arr)	list.insert(i,head);
    Node* ans = reverseKLinkedList(head,k);
    list.printList(ans);
    return 0;
}