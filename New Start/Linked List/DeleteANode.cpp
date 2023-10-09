/*
    Delete given node in a Linked List : O(1) approach

    Problem Statement:  Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list instead, you will be given access to 
                        the node to be deleted directly. It is guaranteed that the node to be deleted is not a tail node in the list.    

    Problem Link:   https://leetcode.com/problems/delete-node-in-a-linked-list/
                    https://www.codingninjas.com/studio/problems/1105578?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/delete-given-node-in-a-linked-list-o1-approach/

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

        Node* getNode(Node* &head, int n){
            Node* temp =  head;
            while(temp->data != n)  temp = temp->next;
            return temp;
        }
};

//Optimal Approach
//TC: O(1)
//SC: O(1)
void deleteNodeOptimal(Node* &node){
    node->data = node->next->data;
    node->next = node->next->next;
    return;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    Node* head = NULL;
    linkedListClass list;
    for(auto i:arr)	list.insert(i,head);

    Node* todelete = list.getNode(head,2);
    deleteNodeOptimal(todelete);
    list.printList(head);
    return 0;
}