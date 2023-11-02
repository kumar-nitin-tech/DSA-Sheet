/*
    Starting point of loop in a Linked List

    Problem Statement:  Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

    Problem Link:   https://leetcode.com/problems/linked-list-cycle-ii/
                    https://www.codingninjas.com/studio/problems/1112628?topList=striver-sde-sheet-problems&leftPanelTabValue=PROBLEM

    Refer:  https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/

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
//SC:   O(N)
Node* CycleNode(Node* head){
    unordered_map<Node*, int> mp;
    int i = 0;
    while(head != NULL){
        if(mp.find(head) != mp.end())   return head;
        mp[head] = i++;
        head = head->next;
    }
    return head;
}

//Optimal Approach
//TC: O(n)
//SC:O(1)
Node* cycleNodeOptimal(Node* head){
    Node* slow = head, *fast = head, *entry = head;

    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            while(entry!=slow){
                slow = slow->next;
                entry = entry->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    Node* head = NULL;
    linkedListClass list;
    for(auto i:arr)	list.insert(i,head);
    
    return 0;
}