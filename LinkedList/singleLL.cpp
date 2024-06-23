#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertionAtHead(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *head = new node(data);
        tail = head;
        return;
    }
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void insertionAtTail(node *&head, node *&tail, int data)
{
    if (tail == NULL)
    {
        node *head = new node(data);
        tail = head;
        return;
    }
    node *temp = new node(data);
    tail->next = temp;
    tail = tail->next;
}

void insertionAtPosition(node *&head, node *&tail, int k, int data)
{

    if (k == 1)
    {
        insertionAtHead(head, tail, data);
        return;
    }

    if (head == NULL && tail == NULL)
    {
        node *head = new node(data);
        tail = head;
        return;
    }
    node *temp = new node(data);
    node *pos = head;
    k = k - 2;
    while (k)
    {
        pos = pos->next;
        k--;
    }
    temp->next = pos->next;
    pos->next = temp;
}
void deleteNode(node *&head, node *&tail, int position)
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        delete temp;

        if (head == nullptr)
        {
            tail = nullptr;
        }
    }
    else
    {
        node *current = head;
        int count = 1;

        while (current != nullptr && count < position - 1)
        {
            current = current->next;
            count++;
        }

        if (current == nullptr || current->next == nullptr)
        {
            cout << "Position is out of bounds.\n";
            return;
        }

        node *temp = current->next;
        current->next = temp->next;
        delete temp;

        if (current->next == nullptr)
        {
            tail = current;
        }
    }
}

void printLL(node *head)
{
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node *head = new node(10);
    node *tail = head;

    insertionAtTail(head, tail, 20);
    insertionAtTail(head, tail, 30);
    insertionAtTail(head, tail, 40);
    insertionAtTail(head, tail, 50);
    insertionAtHead(head, tail, 100);

    insertionAtPosition(head, tail, 3, 11);
    printLL(head);
    return 0;
}