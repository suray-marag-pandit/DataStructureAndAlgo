#include <iostream>
using namespace std;

// Node class for DLL
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

// Function to print the list forward
void printForward(Node* head) {
    cout << "Forward: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to print the list backward
void printBackward(Node* tail) {
    cout << "Backward: ";
    Node* temp = tail;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Insert at Head
void insertAtHead(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node(data);

    if (head == NULL) { // Empty list
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert at Tail
void insertAtTail(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node(data);

    if (tail == NULL) { // Empty list
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Insert at Position (1-based index)
void insertAtPosition(Node*& head, Node*& tail, int position, int data) {
    if (position <= 1) {
        insertAtHead(head, tail, data);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        insertAtTail(head, tail, data);
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete at Head
void deleteAtHead(Node*& head, Node*& tail) {
    if (head == NULL) return; // Empty list

    Node* temp = head;
    if (head == tail) { // Single element
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    delete temp;
}

// Delete at Tail
void deleteAtTail(Node*& head, Node*& tail) {
    if (tail == NULL) return; // Empty list

    Node* temp = tail;
    if (head == tail) { // Single element
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete temp;
}

// Delete at a given position (1-based index)
void deleteAtPosition(Node*& head, Node*& tail, int position) {
    if (head == NULL) return; // Empty list

    if (position == 1) {
        deleteAtHead(head, tail);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) return; // Position out of bounds

    if (temp == tail) {
        deleteAtTail(head, tail);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

// Driver code
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Insertion at head
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);

    // Insertion at tail
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    // Insertion at position
    insertAtPosition(head, tail, 3, 25); // Insert 25 at position 3
    insertAtPosition(head, tail, 7, 60); // Insert 60 at the end

    cout << "Initial List:" << endl;
    printForward(head);
    printBackward(tail);

    // Deletions
    deleteAtHead(head, tail);
    cout << "\nAfter deleting head:" << endl;
    printForward(head);

    deleteAtTail(head, tail);
    cout << "\nAfter deleting tail:" << endl;
    printForward(head);

    deleteAtPosition(head, tail, 3);
    cout << "\nAfter deleting position 3:" << endl;
    printForward(head);

    return 0;
}
