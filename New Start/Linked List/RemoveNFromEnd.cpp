/*
    Remove N-th node from the end of a Linked List

    Problem Statement:   Given a linked list, and a number N. Find the Nth node from the end of this linked list and delete it. Return the head of the new modified linked list.  

    Problem Link:   https://leetcode.com/problems/remove-nth-node-from-end-of-list/
                   https://www.codingninjas.com/studio/problems/799912?topList=striver-sde-sheet-problems 

    Refer:  https://takeuforward.org/data-structure/remove-n-th-node-from-the-end-of-a-linked-list/

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

//Brute Force
//TC: O(2N)
//SC: O(1)
Node* deleteNNode(Node* &head, int k){
    int n = 0;
    Node* temp = head;
    while(temp != NULL){
        n++;
        temp = temp->next;
    }
    if(n==k)    return head->next;
    temp = head;
    for(int i=1; i<n-k; i++){
        temp = temp->next;
    }
    Node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
    return head;
}

//Optimise 
//TC: O(N)
//SC:   O(1)
Node *deleteNNodeOptimal(Node *&head, int k){
    Node* start = new Node();
    start->next = head;
    Node *slow = start, *fast = start;

    for(int i=0; i<k; i++){
        fast = fast -> next;
    }

    while(fast->next != NULL){
        slow = slow ->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return start->next;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    Node* head = NULL;
    linkedListClass list;
    for(auto i:arr)	list.insert(i,head);
    Node* node = deleteNNodeOptimal(head,k);
    list.printList(node);
    return 0;
}