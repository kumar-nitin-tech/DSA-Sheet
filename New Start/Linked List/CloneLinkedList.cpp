/*
    Clone Linked List with Random and Next Pointer

    Problem Statement:  Given a Linked list that has two pointers in each node and one of which points to the first node and the other points to any random node. Write a 
                        program to clone the LinkedList.  

    Problem Link:   https://leetcode.com/problems/copy-list-with-random-pointer/
                    https://www.codingninjas.com/studio/problems/clone-a-linked-list-with-random-pointers_983604

    Refer:  https://takeuforward.org/data-structure/clone-linked-list-with-random-and-next-pointer/

*/

#include<bits/stdc++.h>
using namespace std;

//Structure of Linked List
class Node{
    public:
        int data;
        Node* next, *random;

        Node(int val){
            data = val;
            next = NULL;
            random = NULL;
        }
        Node(){
            data = 0;
            next = NULL;
            random = NULL;
        }
};

//Brute Force (Using hashmap)
//TC: O(N)
//SC: O(N)
Node* cloneLinkedListBrute(Node *head){
    unordered_map<Node*, Node*> mp;
    Node* temp = head;
    while(temp != NULL){
        Node* newNode = new Node(temp->data);
        mp[temp] = newNode;
        temp = temp->next;
    }
    Node* t = head;
    while(t!=NULL){
        Node* node = mp[t];
        node->next = (t->next!=NULL) ? mp[t->next]: NULL;
        node->random = (t->random!= NULL)? mp[t->random]:NULL;
        t = t->next;
    }
    return mp[head];
}

//Optimal Approach
//TC: O(N)
//SC: O(1)
Node* cloneLinkedListOptimal(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        Node* copy = new Node(temp->data);
        copy->next = temp->next;
        temp->next = copy;
        temp = temp->next->next;
    }

    temp = head;
    while(temp!= NULL){
        if(temp->random != NULL)
            temp->next->random = temp->random->next;
        temp = temp->next->next;
    }
    Node* dummy = new Node(), *itr = dummy;
    temp = head;
    Node* fast;
    while(temp != NULL){
        fast = temp->next->next;
        itr->next = temp->next;
        temp->next =fast;
        itr = itr->next;
        temp = fast;
    }
    return dummy->next;
}

int main(){
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    return 0;
}