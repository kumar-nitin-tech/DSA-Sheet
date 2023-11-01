/*
    Detect a Cycle in a Linked List
   
    Problem Statement:  Given head, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list if there is some node in the 
                        list that can be reached again by continuously following the next pointer.
                        Return true if there is a cycle in the linked list. Otherwise, return false.  

    Problem Link:   https://leetcode.com/problems/linked-list-cycle/
                    https://www.codingninjas.com/studio/problems/628974?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/detect-a-cycle-in-a-linked-list/

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
//TC: O(N)
//SC: O(N)
bool detectCycleBrute(Node* &head){
    unordered_set<Node*> set;
    while(head != NULL){
        if(set.find(head) != set.end()){
            return true;
        }
        set.insert(head);
        head = head->next;
    }
    return false;
}

//Optimised Approach
//TC: O(N)
//SC: O(1)
//fast and slow pointer
bool detectCycleOptimal(Node* &head){
    if(head == NULL)    return false;
    Node* fast = head, *slow = head;
    //if fast and slow collide each other means its cycle and no need to go further and check cycle starting point
    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast)    return true;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    Node* head = NULL;
    linkedListClass list;
    for(auto i:arr)	list.insert(i,head);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    cout<<detectCycleBrute(head);
    return 0;
}