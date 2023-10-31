/*
    Find intersection of Two Linked Lists

    Problem Statement:  Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no 
                        intersection at all, return null.

    Problem Link:   https://leetcode.com/problems/intersection-of-two-linked-lists/
                    https://www.codingninjas.com/studio/problems/630457?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/

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
//TC: O(N*M)
//SC: O(1)
Node* IntersectionNodeBrute(Node *&headA, Node* &headB){
    while(headA != NULL){
        Node* temp = headB;
        while(temp != NULL){
            if(temp == headA){
                return headA;
            }
            temp = temp->next;
        }
        headA = headA->next;
    }
    return NULL;
}

//Better Approach using Hashmap
//TC: O(N+M)
//SC: O(N) or O(M)
Node* IntersectionNodeBetter(Node* &headA, Node* &headB){
    unordered_set<Node*> set;
    while(headA != NULL){
        set.insert(headA);
        headA = headA->next;
    }    

    while(headB != NULL){
        if(set.find(headB) != set.end()){
            return headB;
        }
        headB = headB -> next;
    }
    return NULL;
}

//Optimal Approach
//TC: O(2(M+N))
//SC: O(1)
//1st Optimal Approach
Node* IntersectionNodeOptimal1(Node* &headA, Node* &headB){
    //We have to find the len of both linked list
    int len1 = 0, len2 = 0;
    Node* temp1 = headA, *temp2 = headB;
    while(temp1 != NULL){
        len1++;
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        len2++;
        temp2 = temp2->next;
    }

    int diff = len1 - len2;
    //if len1 is greater then headA is larger or else headB
    if(diff >= 0){
        while(diff-- != 0)  headA = headA->next;
    }else{
        while(diff++ != 0)  headB = headB->next;
    }

    while(headA != NULL){
        if(headA == headB)  return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}

//2nd Approach
Node* IntersectionNodeOptimal2(Node* &headA, Node* &headB){
    Node* d1 = headA, *d2 = headB;
    while(d1 != d2){
        d1 = d1==NULL? headB:d1->next;
        d2 = d2==NULL? headA:d2->next;
    }
    return d1;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n), arr2(m);
    for(auto &i:arr)    cin>>i;
    for(auto &i:arr2)   cin>>i;
    Node* headA = NULL, *headB = NULL;
    linkedListClass list;
    for(auto i:arr)	list.insert(i,headA);
    for(auto i:arr2)	list.insert(i,headB);

    Node *ans = IntersectionNodeBrute(headA,headB);
    cout<<ans->data<<endl;
    return 0;
}