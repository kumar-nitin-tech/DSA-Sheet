/*
    LFU Cache

    Problem Statement:     Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

    Problem Link:   https://leetcode.com/problems/lfu-cache/description/

    Refer:  https://www.youtube.com/watch?v=0PSB9y8ehbk&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=78

*/

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int val;
        int key;
        int cnt;
        node* next;
        node* prev;
        node(int _key, int _val){
            key = _key;
            val = _val;
            cnt = 1;
        }
};


//LRU for tie
class List{
    public:
    int size;
    node* head;
    node* tail;

    List(){
        head = new node(-1,-1);
        tail = new node(-1,-1);
        head ->next = tail;
        tail ->prev = head;
        size = 0;
    }

    void addFront(node* Node){
        node * temp = head->next;
        Node->next = temp;
        Node->prev = head;
        head->next = Node;
        temp->prev = Node;
        size++;
    }

    void deleteNode(node* Node){
        node *delNodePrev = Node->prev;
        node *delNodeNext = Node->next;
        delNodePrev->next = delNodeNext;
        delNodeNext->prev = delNodePrev;
        size--;
    }

};

class LFUCache {
    unordered_map<int, node*> m;
    unordered_map<int, List*> freq;
    int minFreq;
    int maxSizeCache;
    int currSize;
    public:
        LFUCache(int capacity) {
            maxSizeCache = capacity;
            minFreq = 0;
            currSize = 0;
        }
        
        void updateFreqList(node* Node){
            m.erase(Node->key);
            freq[Node->cnt]->deleteNode(Node);
            if(Node->cnt == minFreq && freq[Node->cnt]->size == 0){
                minFreq++;
            }

            List *nextHighFreq = new List();
            if(freq.find(Node->cnt+1) != freq.end()){
                nextHighFreq = freq[Node->cnt+1];
            }
            Node->cnt += 1;
            nextHighFreq->addFront(Node);
            m[Node->key] = Node;
            freq[Node->cnt] = nextHighFreq;
        }

        int get(int key) {
            if(m.find(key) != m.end()){
                node *temp = m[key];
                int ans = temp->val;
                updateFreqList(temp);
                return ans;
            }
            return -1;
        }
        
        void put(int key, int value) {
            if(maxSizeCache == 0)   return;

            if(m.find(key) != m.end()){
                node* Node = m[key];
                Node->val = value;
                updateFreqList(Node);
            }
            else{
                if(currSize == maxSizeCache){
                    List *list = freq[minFreq];
                    //remove key from node map
                    m.erase(list->tail->prev->key);
                    freq[minFreq]->deleteNode(list->tail->prev);
                    currSize--;
                }
                currSize++;

                //new value to be added in list 
                minFreq = 1;
                List *listFreq = new List();
                //check if the minFreq ele is present in freq list if present add the list to the freqList
                if(freq.find(minFreq) != freq.end()){
                    listFreq = freq[minFreq];
                }

                node* Node = new node(key,value);
                listFreq->addFront(Node);
                //add to hashmap;
                m[key] = Node;
                freq[minFreq] = listFreq; 
            }
        }
};


int main(){
    return 0;
}