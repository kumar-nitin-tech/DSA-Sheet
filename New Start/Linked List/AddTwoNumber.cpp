/*
    Add two numbers represented as Linked Lists
   
    Problem Statement:  Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes 
                        contains a single digit. Add the two numbers and return the sum as a linked list.

    Problem Link:   https://leetcode.com/problems/add-two-numbers/
                    https://www.codingninjas.com/studio/problems/add-two-numbers-as-linked-lists_1170520?topList=striver-sde-sheet-problems
    
    Refer:  https://takeuforward.org/data-structure/add-two-numbers-represented-as-linked-lists/

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

//Optimal Approach
//TC: O(max(n,m))
//SC: O(1)
Node* addTwoNumber(Node* l1, Node* l2){
    Node* dummy = new Node(0), *temp = dummy;
    int carry = 0; 
    while((l1 != NULL || l2 != NULL) || carry){
        int sum = 0;
        if(l1 != NULL){
            sum += l1 ->data;
            l1 = l1->next;
        }
        if(l2 != NULL){
            sum += l2->data;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum/10;
        Node *sumNode = new Node(sum%10);
        temp ->next = sumNode;
        temp = temp->next;
    }
    Node *ans = dummy->next;
    delete dummy;
    return ans;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n), brr(m);
    for(auto &i:arr)    cin>>i;
    for(auto &i:brr)    cin>>i;
    Node* l1 = NULL, *l2 = NULL;
    linkedListClass list;
    for(auto i:arr)	list.insert(i,l1);
    for(auto i:brr) list.insert(i,l2);

    Node *newNode = addTwoNumber(l1,l2);
    list.printList(newNode);

    return 0;
}