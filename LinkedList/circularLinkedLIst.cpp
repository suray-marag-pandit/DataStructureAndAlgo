#include <iostream>
using namespace std;

// Node class for Circular Linked List
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        cout << "Node with value " << data << " deleted.\n";
    }
};

// Function to print circular linked list
void printCircular(Node* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Insert at head
void insertAtHead(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node(data);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head;  // Point to itself
        return;
    }

    newNode->next = head;
    head = newNode;
    tail->next = head; // Maintain circular nature
}

// Insert at tail
void insertAtTail(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node(data);

    if (tail == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head; // Point to itself
        return;
    }

    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
}

// Insert at a given position (1-based index)
void insertAtPosition(Node*& head, Node*& tail, int position, int data) {
    if (position <= 1) {
        insertAtHead(head, tail, data);
        return;
    }

    if (head == NULL) {
        insertAtHead(head, tail, data);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (temp->next == head) {
        insertAtTail(head, tail, data);
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at head
void deleteAtHead(Node*& head, Node*& tail) {
    if (head == NULL) return; // Empty list

    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    Node* temp = head;
    head = head->next;
    tail->next = head; // Maintain circular link
    delete temp;
}

// Delete at tail
void deleteAtTail(Node*& head, Node*& tail) {
    if (head == NULL) return; // Empty list

    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    temp->next = head;
    delete tail;
    tail = temp;
}

// Delete at given position (1-based index)
void deleteAtPosition(Node*& head, Node*& tail, int position) {
    if (head == NULL) return; // Empty list

    if (position == 1) {
        deleteAtHead(head, tail);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (temp->next == head) {
        cout << "Position out of bounds.\n";
        return;
    }

    Node* nodeToDelete = temp->next;

    // If deleting tail
    if (nodeToDelete == tail) {
        deleteAtTail(head, tail);
        return;
    }

    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

// Driver Code
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Insertions
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);

    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    insertAtPosition(head, tail, 3, 25);
    insertAtPosition(head, tail, 10, 60); // Goes to tail

    cout << "Initial List:\n";
    printCircular(head);

    // Deletions
    deleteAtHead(head, tail);
    cout << "\nAfter deleting head:\n";
    printCircular(head);

    deleteAtTail(head, tail);
    cout << "\nAfter deleting tail:\n";
    printCircular(head);

    deleteAtPosition(head, tail, 3);
    cout << "\nAfter deleting position 3:\n";
    printCircular(head);

    deleteAtPosition(head, tail, 10); // Out of bounds
    return 0;
}
