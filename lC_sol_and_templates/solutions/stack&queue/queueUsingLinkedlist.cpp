#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition of linked list
 * class Node {
 * 
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 * 
 * Definition of Queue
 * struct Queue {
 *   Node* front;
 *   Node* rear;
 *   void push(int);
 *   int pop();
 *   
 *   Queue() {
 *       front = rear = NULL;
 *   }
 * };
 */

void Queue::push(int x) {
    Node* newNode = new Node(x);
    if(front == nullptr){
        front = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = rear->next;
    }
}

int Queue::pop() {
    if(front == nullptr) return -1;
    int curr = front->data;
    front = front->next;
    return curr;
}