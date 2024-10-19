/*
    LRU Cache
    Problem Statement:Design a data structure that follows the constraints of Least Recently Used (LRU) cache”.
Implement the LRUCache class:

LRUCache(int capacity) we need to initialize the LRU cache with positive size capacity.
int get(int key) returns the value of the key if the key exists, otherwise return -1.
Void put(int key,int value), Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.if the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.  

    Problem Link:   https://leetcode.com/problems/lru-cache/description/

    Refer:  https://takeuforward.org/data-structure/implement-lru-cache/

*/

#include<bits/stdc++.h>
using namespace std;


class LRU{
    public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;

        node(int _key, int _value){
            key = _key;
            val = _value;
        }
    };

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    int size;
    unordered_map<int, node*> hashMap;
    
    LRU(int _size){
        size = _size;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(node* Node){
        node* delPrev = Node->prev;
        node* delNext = Node->next;

        delPrev-> next = delNext;
        delNext -> prev = delPrev;
    }

    void addNode(node* Node){
        node* temp = head->next;
        Node->prev = head;
        Node-> next = temp;
        head->next = Node;
        temp->prev = Node;
    }

    void put(int __key, int __val){
        if(hashMap.find(__key) != hashMap.end()){
            //we have to remove the present node in the list 
            node* curr = hashMap[__key];
            hashMap.erase(__key);
            deleteNode(curr);
        }

        if(hashMap.size() == size){
            hashMap.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new node(__key,__val));
        hashMap[__key] = head->next;

    }

    int get(int __key){
        if(hashMap.find(__key) != hashMap.end()){
            node* resNode = hashMap[__key];
            int ans = resNode->val;
            hashMap.erase(__key);
            deleteNode(resNode);
            addNode(resNode);
            hashMap[__key] = head->next;
            return ans;
        }
        return -1;
    }
};

int main(){
    return 0;
}