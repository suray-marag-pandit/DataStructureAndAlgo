#include <iostream>
using namespace std;

// ----------------------
// Node Class Definition
// ----------------------
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Memory freed for node with data: " << data << endl;
    }
};

// ----------------------
// Insert at Head
// ----------------------
void insertionAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        tail = head;
        return;
    }
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

// ----------------------
// Insert at Tail
// ----------------------
void insertionAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        tail = head;
        return;
    }
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

// ----------------------
// Insert at Position
// ----------------------
void insertionAtPosition(Node *&head, Node *&tail, int position, int data)
{
    if (position == 1)
    {
        insertionAtHead(head, tail, data);
        return;
    }

    if (head == NULL && tail == NULL)
    {
        head = new Node(data);
        tail = head;
        return;
    }

    Node *pos = head;
    position = position - 2; // Move one position behind target

    while (position && pos->next != NULL)
    {
        pos = pos->next;
        position--;
    }

    if (pos->next == NULL)
    {
        insertionAtTail(head, tail, data);
        return;
    }

    Node *temp = new Node(data);
    temp->next = pos->next;
    pos->next = temp;
}

// ----------------------
// Delete Node
// ----------------------
void deleteNode(Node *&head, Node *&tail, int position)
{
    // Case 0: Empty list
    if (head == NULL)
    {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    // Case 1: Delete head
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;

        // If list becomes empty after deletion
        if (head == NULL)
        {
            tail = NULL;
        }

        delete temp;
        return;
    }

    // Case 2: Delete at position (middle or tail)
    Node *prev = head;
    Node *curr = head->next;
    int count = 2;

    while (curr != NULL && count < position)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    // If position is greater than length
    if (curr == NULL)
    {
        cout << "Position out of range. No deletion performed.\n";
        return;
    }

    // If deleting last node, update tail
    if (curr->next == NULL)
    {
        tail = prev;
    }

    prev->next = curr->next;
    delete curr;
}

// reversing the linkedlist

void reverseLinkedList(Node *&head, Node *&tail)
{
    Node *prev = NULL;
    Node *current = head;
    tail = head;

    while (current)
    {
        head = head->next;
        current->next = prev;

        prev = current;
        current = head;
        // delete temp;
    }
    head = prev;
}

// recursive reverse ll

void reverseLinkedListRecursive(Node *&head, Node *&tail, Node *prev, Node *current)
{
    if (current == NULL)
    {
        head = prev;
        return;
    }

    reverseLinkedListRecursive(head, tail, current, current->next);
    current->next = prev;
    tail = current;

    // Node *curr = NULL;

    // while (head != NULL)
    // {
    //     curr = head->next;
    //     head->next = prev;
    //     prev = head;
    //     head =curr;
    // }
    // head = prev;
}

//one more recursive approach 
Node *  reverse(Node * head){
    if(head->next ==NULL || head == NULL)
        return head;

    Node * temp = reverse(head->next);
    temp->next = head;
    return head;


}

// ----------------------
// Print Linked List
// ----------------------
void printLL(Node *head)
{
    cout << "\nLinked List: ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// ----------------------
// Main Function
// ----------------------
int main()
{
    Node *linkedlist = new Node(10);
    Node *tail = linkedlist;

    // Insert at Head
    insertionAtHead(linkedlist, tail, 20);
    insertionAtHead(linkedlist, tail, 30);
    insertionAtHead(linkedlist, tail, 40);

    // Insert at Tail
    insertionAtTail(linkedlist, tail, 1);
    insertionAtTail(linkedlist, tail, 2);
    insertionAtTail(linkedlist, tail, 3);

    // Insert at Specific Positions
    insertionAtPosition(linkedlist, tail, 1, 100);  // At head
    insertionAtPosition(linkedlist, tail, 5, 200);  // Middle
    insertionAtPosition(linkedlist, tail, 10, 300); // Tail

    printLL(linkedlist);

    cout << "reverseLinkedList" << endl;

    Node *pointer = NULL;
    // reverseLinkedListRecursive(linkedlist, tail, pointer, linkedlist);

    reverse(linkedlist);
    printLL(linkedlist);

    cout << tail->data << endl;

    // ------------------
    // Deletion Examples
    // // ------------------
    // cout << "\nDeleting head (position 1)" << endl;
    // deleteNode(linkedlist, tail, 1);
    // printLL(linkedlist);

    // cout << "\nDeleting last node" << endl;
    // deleteNode(linkedlist, tail, 9); // dynamically calculated
    // printLL(linkedlist);

    // cout << "\nDeleting node at position 4" << endl;
    // deleteNode(linkedlist, tail, 4);
    // printLL(linkedlist);

    // cout << "\nDeleting invalid position" << endl;
    // deleteNode(linkedlist, tail, 20);

    return 0;
}

// #include<iostream>
// using namespace std;

// class Node{
//     public:
//     int data;
//     Node * next;

//     Node(int data){
//         this->data = data;
//         this->next = NULL;
//     }

// };

// void insertionAtHead(Node * &head,Node *&tail,int data){
//     if(head==NULL){
//         head = new Node(data);
//         tail = head;
//         return;
//     }
//     // Node pointerHead = this;
//     Node * temp = new Node(data);
//     temp->next = head;
//     head = temp;
// }

// void insertionAtTail(Node * &head, Node*&tail,int data){
//     if(head==NULL){
//         head = new Node(data);
//         tail = head;
//         return;
//     }
//     Node * temp = new Node(data);
//     tail->next = temp;
//     tail = temp;

// }

// void insertionAtPosition(Node * &head, Node* &tail,int position,int data){
//     if(position==1){
//         insertionAtHead(head,tail,data);
//         return;
//     }

//     if (head == NULL && tail == NULL)
//     {
//         head = new Node(data);
//         tail = head;
//         return;
//     }

//     Node * pos = head;
//     position = position-2;

//     while(position){
//         pos = pos->next;
//         position--;
//     }

//     if(pos->next==NULL){
//         insertionAtTail(head,tail,data);
//         return;
//     }
//     Node * temp = new Node(data);
//     temp->next = pos->next;
//     pos->next = temp;
// }

// void printLL(Node * head){
//     while(head!=NULL){
//         cout<<head->data<<" ";
//         head=head->next;
//     };
// }

// int main(){

//     Node * linkedlist = new Node(10);
//     cout<< linkedlist->data<<endl;
//     Node * tail = linkedlist;

//     insertionAtHead(linkedlist,tail,20);
//     insertionAtHead(linkedlist,tail,30);
//     insertionAtHead(linkedlist,tail,40);
//     insertionAtHead(linkedlist,tail,50);

//     insertionAtTail(linkedlist,tail,1);
//     insertionAtTail(linkedlist,tail,2);
//     insertionAtTail(linkedlist,tail,3);
//     insertionAtTail(linkedlist,tail,4);

//     insertionAtPosition(linkedlist,tail,1,100);
//     insertionAtPosition(linkedlist,tail,10,100);
//     insertionAtPosition(linkedlist,tail,6,100);

//     insertionAtPosition(linkedlist,tail,13,99);
//     printLL(linkedlist);
//     return 0;
// }