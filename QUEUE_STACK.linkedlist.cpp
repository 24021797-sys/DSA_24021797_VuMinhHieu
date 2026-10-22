#include <iostream>
#include "link_list"
using namespace std;

//STACK
struct Stack {
    Node* topNode; // Ð?nh stack chính là head c?a linked list

    Stack() {
        topNode = nullptr;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    // Push: Chèn thêm phan tu vao dau danh sach -> O(1)
    void push(int val) {
        Node* dummyTail = nullptr; 
        insertHead(topNode, dummyTail, val);
    }

    // Pop: xoa phan tu o dau -> O(1)
    void pop() {
        Node* dummyTail = nullptr;
        deleteHead(topNode, dummyTail);
    }

    void displayStack() {
        cout << "Stack (Top -> Bottom): ";
        display(topNode);
    }
};

//QUEUE
struct Queue {
    Node* head;
    Node* tail;

    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    // Enqueue: them phan tu vao cuoi dung tail -> O(1)
    void enqueue(int val) {
        insertTail(head, tail, val);
    }

    // Dequeue: xoa node dau tien-> O(1)
    void dequeue() {
        deleteHead(head, tail);
    }

    void displayQueue() {
        cout << "Queue (Front -> Rear): ";
        display(head);
    }
    
    int front() {
        if (isEmpty()) {
            return -1; 
        }
        return head->data;
    }
};

