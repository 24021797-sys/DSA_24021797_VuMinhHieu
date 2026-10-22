#include <iostream>
using namespace std;

// 1. C?u trúc Node
struct Node {
    int data;
    Node* next;
};

// 2. Hàm riêng d? t?o m?t node m?i
Node* createNode(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

// 3. Thêm vào d?u danh sách
void insertHead(Node*& head, Node*& tail, int val) {
    Node* newNode = createNode(val);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// 4. Thêm vào cu?i danh sách (dùng tail O(1))
void insertTail(Node*& head, Node*& tail, int val) {
    Node* newNode = createNode(val);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// 5. Chèn vào v? trí b?t k? (chèn gi?a)
void insertAt(Node*& head, Node*& tail, int val, int position) {
    if (position <= 1) {
        insertHead(head, tail, val);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp == tail) {
        insertTail(head, tail, val);
    } else {
        Node* newNode = createNode(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// 6. Xóa d?u danh sách
void deleteHead(Node*& head, Node*& tail) {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    if (head == nullptr) {
        tail = nullptr; // N?u danh sách tr?ng sau khi xóa
    }
}

// 7. Xóa cu?i danh sách
void deleteTail(Node*& head, Node*& tail) {
    if (head == nullptr) {
        return;
    }

    if (head == tail) { // Ch? có 1 ph?n t?
        delete head;
        head = tail = nullptr;
        return;
    }

    // Tìm node áp chót
    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = nullptr;
}

// 8. In danh sách
void display(Node* head) {
    if (head == nullptr) {
        cout << "Danh sach rong!\n";
        return;
    }

    Node* temp = head;
    cout << "Danh sach: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

