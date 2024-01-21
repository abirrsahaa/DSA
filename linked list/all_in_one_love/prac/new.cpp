// You are using GCC
// You are using GCC
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    // 4 5
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void append(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
bool present(int data, Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    while (head != NULL)
    {
        if (head->data == data)
        {
            return true;
        }
    }
    return false;
}
void display(Node *head)
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
int main()
{
    int n;
    cin >> n;
    Node *head = NULL;
    Node *tail = NULL;
    Node *head1 = NULL;
    Node *tail1 = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        append(head, tail, data);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int data;
        cin >> data;
        append(head1, tail1, data);
    }
    Node *head2 = NULL;
    Node *tail2 = NULL;
    display(head);
    if (head1 == NULL)
    {
        return 0;
        ;
    }
    Node *temp3 = head;
    while (temp3 != NULL)
    {
        if (!present(temp3->data, head1))
        {
            append(head2, tail2, temp3->data);
        }
        temp3 = temp3->next;
    }
    cout << endl;
    display(head2);
}