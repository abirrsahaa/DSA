// task to understand linked list AND improve problem solving using a new data structure

// fine !!
// lets start with creation and then we will focus on insertion deletion and finding middle finding length
// printing the linked list and reverse the linked list

// linked list is made up of nodes with one having integer data and another having a pointer

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // creating the constructors
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    // creating the parameterized constructors
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
int length(Node *&head)
{
    if (head == NULL)
    {
        return 0;
    }
    int c = 0;
    while (head != NULL)
    {
        c++;
        head = head->next;
    }
    return c;
}

// now lets create functions for inserting at the head and at the tail and even at the middle
// also we have to create for deletion
// with also printing the entire linked list

void inserthead(Node *&head, Node *&tail, int data)
{
    // i need to insert a new node at the head
    // lets discuss case
    // if there is no node this is the first node
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    // if there is atleast one node it means there is need to insert at head and update the head
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertattail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }

    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
    return;
}

void print(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void insertatposition(Node *&head, Node *&tail, int data, int position)
{
    int size = length(head);
    // case-1 empty linked list
    if (size == 0)
    {
        inserthead(head, tail, data);
        return;
    }
    // if position entered is more than the size and less than 0
    if (position < 0)
    {
        inserthead(head, tail, data);
        return;
    }
    if (position > size)
    {
        insertattail(head, tail, data);
        return;
    }

    // now if valid index received
    //
    int c = 0;
    Node *curr = head;
    while (c < position && curr != NULL)
    {
        curr = curr->next;
        c++;
    }
    Node *temp = new Node(data);
    temp->next = curr->next;
    curr->next = temp;
}

void middle(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    int size = length(head);
    int c = 1;
    while (c < size / 2)
    {
        head = head->next;
        c++;
    }
    cout << head->data << " ";
    return;
}

void deleted(Node *&head, int position, Node *&tail)
{
    // case 1 -there exists no node in the linked list
    // therefore return
    if (head == NULL)
    {
        return;
    }
    // case 2-delete the first node
    //  deleting the first node can be a bit tricky as because
    //  if it is a single node then upon deleting the node things will get empty
    //  if it is not a single node then upon deleting the node we need to updat ethe head of the linked list
    //  also another case woulod be when there is a need of deleting the last node where we need to update the tail

    // when there is a single node
    // or deleting the first node of the linked list
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    // when deleting the last node
    int size = length(head);
    if (position == size)
    {
        int i = 1;
        Node *prev = head;
        while (i < position - 1)
        {
            prev = prev->next;
            i++;
        }
        Node *temp = prev->next;
        tail = prev;
        prev->next = NULL;
        delete temp;
        return;
    }

    // now anywhere in the linked list
    int i = 1;
    Node *prev = head;
    while (i < position - 1)
    {
        prev = prev->next;
        i++;
    }
    Node *temp = prev->next;
    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
    return;
}

int main()
{

    cout << "enter the no of elements-->" << endl;
    int n;
    cin >> n;
    Node *head;
    Node *tail;
    for (int i = 0; i < n; i++)
    {
        int data;
        cout << "enter the data of the node -->" << endl;
        cin >> data;
        inserthead(head, tail, data);
    }
    cout << "printing the linked list by inserting at the tail !!" << endl;
    print(head);
}