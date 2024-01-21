// what i have realised is that i will be noting down the problems
// i need to review and also have logical unclarity in them
// question 1-> reverse k nodes

// lets get my fuxking hands dirty

// create a ll
#include <iostream>
using namespace std;

class Node
{
public:
    // a node of a linked list consists of a data section and a pointer section which points to the next node
    int data;
    Node *next;

    // creating the constructors
    // first the default constructor
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    // creating the parameterized constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// lets now code some basic stuffs in ll which consist of the building blocks for all the programming
// insert at head
// insert at tail
// insert at a position which also includes inserting at the middle
// delete a node

// insert at head
void insertathead(Node *&head, Node *&tail, int data)
{
    // 2 ta case hoibo
    // first case hoise amar head null that is ami jei node ta lagaite jaitasi idai amar first node
    // tahole ai node ta te e amar head tail dunoda thakbo
    // now handling first case
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }

    // now second case that is there is atleast a single node in the linked list
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}

// insert at tail
void insertattail(Node *&head, Node *&tail, int data)
{
    // 2 ta case hoibo
    // first case hoise amar haed null that is amni node ta lagaite jaitasi idai amar first node
    // tahole ai node ta te e amr head tail dunoda thakbo
    // now handling the first case
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }

    // handling the second case
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
}

// printing the linked list
void print(Node *&head)
{
    // handling the null case

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int length(Node *&head)
{
    int l = 0;

    Node *temp = head;

    while (temp != NULL)
    {
        l++;
        temp = temp->next;
        cout << "the lenght got incremented to->" << l << endl;
    }
    cout << "printing" << l << endl;
    return l;
}

// ok so basic tasks left are
// insertion at a position and at a middle
// delete a node
// make a deconstructor for the linked list

// lets try some new things
// lets reverse the linked list
Node *reverse(Node *&prev, Node *&curr)
{
    // base case
    if (curr == NULL)
    {
        return prev;
    }

    Node *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;

    reverse(prev, curr);
}

// now task is to get me accustomed to the questions of linked list
// where we will be dealing with the advanced concepts of looping
// and algorithm like using two pointers as one as fast pointer
// and one as slow pointer
// with this we can easily find the middle of the linked list
// in o(n) time complexity
// not only this we can also find the existence of loop
// which will lead us to various questions like
// finding the existence of loop
// finding and printing the origin of loop
// deleting the loop and making it a linear linked list

// first of all to find the middle of the linked list
// here we will be using the two pointer approach
// which will be having the algo of fast and slow pointer
// now this algo works in a specific way such that when
// the fast pointer covers two distances only then the slow pointer
// will be covering a single distance
Node *middle(Node *&head, Node *&tail)
{
    // handling the case when the linked list is empty
    if (head == NULL)
    {
        cout << "the linked list is empty " << endl;
        return head;
    }

    // handling the case when we have a fucking single node
    if (head->next == NULL)
    {
        // showing that it is a single node !
        return head;
    }

    // now that we have come here its sure that there is at least
    // two nodes in the linked list !
    Node *slow = head;
    // yes we could  have assigned the fast pointer to the head but
    // there is a constraint that if i point it to the head
    // then the slow pointer will always point to the node after the
    // middle node and for that reason we are assigning the head
    // pointer to the head->next
    Node *fast = head->next;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

// now lets get my fucking hands dirty in the concept of loops !!

// now to find loops there are a certain algorithm and one such algorithm
// is by using the slow and fast pointer

bool checkloop(Node *&head)
{

    // handling some unique cases
    // if the linked list is empty
    if (head == NULL)
    {
        cout << "there is no question of loop as the lineked list is empty " << endl;
        return false;
    }

    // if there is a single node
    // its obvious that there is no existence of loop
    if (head->next == NULL)
    {
        return false;
    }

    // handling the cases with more than 1 node
    Node *slow = head;
    Node *fast = head->next;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
            if (slow == fast)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertathead(head, tail, 10);
    insertathead(head, tail, 90);
    insertathead(head, tail, 80);
    insertathead(head, tail, 70);
    insertathead(head, tail, 20);
    insertattail(head, tail, 40);
    insertattail(head, tail, 50);

    Node *temp = new Node(55);
    Node *temp2 = new Node(55);
    Node *temp3 = new Node(55);
    Node *temp4 = new Node(55);
    Node *temp5 = new Node(55);

    temp->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = temp5;
    // temp5->next = temp3;

    cout << "printing the linked list" << endl;
    print(head);

    cout << endl;

    cout << "printing the middle of the linked list" << endl;
    cout << middle(head, tail)->data << endl;

    Node *prev = NULL;
    Node *reversehead = reverse(prev, head);

    cout << "printing the linked list after reversal" << endl;
    print(reversehead);

    cout << endl;
    cout << "printing the middle of the linked list after reversal" << endl;
    cout << middle(reversehead, head)->data
         << endl;

    cout << endl;
    cout << endl;

    cout << "nonetheless the length or the number of nodes in the linked list is ->";
    int number = length(head);
    cout << number << endl;

    bool result = checkloop(temp);
    cout << " the answer to whether the linked list consists of  a loop is ->" << result;
}