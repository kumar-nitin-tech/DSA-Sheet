/*
    Check if given Linked List is Plaindrome

    Problem Statement:  Given the head of a singly linked list, return true if it is a palindrome.

    Problem Link:   https://leetcode.com/problems/palindrome-linked-list/description/
                    https://www.codingninjas.com/studio/problems/799352?topList=striver-sde-sheet-problems&leftPanelTabValue=PROBLEM

    Refer:  https://takeuforward.org/data-structure/check-if-given-linked-list-is-plaindrome/

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
//TC: O(N + N)
//SC: O(N)
bool isPalindrome(Node* head){
    vector<int> ans;
    while(head != NULL){
        ans.push_back(head->data);
        head = head->next;
    }

    int n = ans.size();
    for(int i=0; i<n/2; i++){
        if(ans[i] != ans[n-i-1])    return false;
    }
    return true;
}

Node* reverseLinkedList(Node *head){
    Node* prev = NULL, *nex;
    while(head != NULL){
        nex = head->next;
        head->next = prev;
        prev = head;
        head = nex;
    }
    return prev;
}

Node *middleNode(Node *head){
    Node *slow = head, *fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//Optimal Approach
//TC: O(N)
//SC: O(1)
bool isPalindromeOptimal(Node* &head){
    if(head == NULL || head->next == NULL)  return true;
    Node *middle = middleNode(head);
    Node* revNode = reverseLinkedList(middle->next);
    
    while(revNode != NULL){
         if(revNode->data != head->data) return false;
         revNode = revNode->next;
         head = head->next;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(auto &i:arr)    cin>>i;
        Node* head = NULL;
        linkedListClass list;
        for(auto i:arr)	list.insert(i,head);
        cout<<isPalindromeOptimal(head);
    }
    return 0;
}