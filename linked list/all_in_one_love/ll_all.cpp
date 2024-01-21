#include <iostream>
using namespace std;

// creating the class node by which i will be able to make nodes of the linked list
class Node
{
public:
    // karon akta node r duida part thake akta data arekta hoise pointer jeta next node re point korbo
    int data;
    Node *next;

    // now create the constructors
    Node()
    {
        this->data = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // okkz  so constructors are made that is now i can make nodes of my linked list
};

// how can we print a linked list
// in linked list we always play around the pointer as the pointer of the node is where
// we will be abke to access the node we want !
void print(Node *head)
{
    // now that i have got the pointer i know the address of the head
    // lets store the head in a temporary variable/pointer  and then perform the print operation
    Node *temp = head;
    // as we have got the address we can access the node by this keyword
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// lets find the length of the linked list created
int findlength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

// now lets understand the three basic operations of linked list
// that is insertion(from head and tail and at a particular position ) deletion
int main()
{
}

// class1

#include <iostream>
using namespace std;

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
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
        cout << endl;
    }

    // to get the middle of the linked list !!

    // here dont get cofused with the syntax of the function as because
    // here the return data type is node and it will return a pointer to a node data type

    Node *getMiddle(Node * &head)
    {
        // handling the case when the linked list is empty !
        if (head == NULL)
        {
            cout << "LL is empty" << endl;
            return head;
        }

        // handling the case when there is only a single node !
        // that is if there is a single node then it is only the middle!
        if (head->next == NULL)
        {
            // only 1 node in LL
            return head;
        }

        // handling the case LL have > 1 node

        // here we have use the algoritm of sloww and fast pointer
        // where the fast pointer steps by 2 steps and the slow pointer steps by one steps
        // and there is a catch the slow pointer will only step if and only if the
        // fast poointer has been able to move 2 steps !
        Node *slow = head;
        Node *fast = head;

        while (slow != NULL && fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        // once we are out of the loop that is the the fast pointer has reached to a case when it is null !
        return slow;
    }

    int getLength(Node * head)
    {
        int len = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            len++;
        }
        return len;
    }

    // to reverse k nodes is one of the important concept nd lofic of linked list !!

    Node *reverseKNodes(Node * &head, int k)
    {
        if (head == NULL)
        {
            cout << "LL is empty" << endl;
            return NULL;
        }
        int len = getLength(head);
        if (k > len)
        {
            // cout << "Enter valid value for k " << endl;
            return head;
        }

        // it means number of nodes in LL is >= k
        // Step A: reverse first k nodes of LL
        Node *prev = NULL;
        Node *curr = head;
        Node *forward = curr->next;
        int count = 0;

        while (count < k)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        // Step B: recursive call
        if (forward != NULL)
        {
            // we still have nodes left to reverse
            Node *recursionKaAns = reverseKNodes(forward, k);
            head->next = recursionKaAns;
        }

        // step C: return head of the modified LL
        return prev;
    }

    // its the most imp question and its types of linked list
    // to find loop in linked list we will be using the Floyd's Cycle Detection Algorithm

    // one of the basic thing in loop is that there is no NULL pointer in looping  LL

    bool checkForLoop(Node * &head)
    {
        // handling the case when the loop is empty
        if (head == NULL)
        {
            cout << "LL is empty " << endl;
            return false;
        }
        // handling the case when there is only a single node present
        if (head->next == NULL)
        {
            cout << "LL is of only one node and there is no loop in the LL" << endl;
            return false;
        }

        // now handling the case where linked list has nodes >1
        // why so? as even a LL containing 2 nodes can form a loop consider a circular linked list with 2 nodes

        Node *slow = head;
        Node *fast = head;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }

            // the below condition is where all the logic of the algorithm is !
            // make sure are thorough with the mathematical proof of how its actually working

            if (slow == fast)
            {
                // loop present
                return true;
            }
        }
        // fast NULL hogya
        return false;
    }

    Node *startingPointLoop(Node * &head)
    {
        if (head == NULL)
        {
            cout << "LL is empty " << endl;
            return NULL;
        }

        Node *slow = head;
        Node *fast = head;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }

            if (slow == fast)
            {
                slow = head;
                break;
            }
        }
        // one doubt here is that the breaking and coming out of the loop can be of two ways
        // either we have found the loop and the slow and fast pointer have met and we broke open the loop
        // or there is no loop and we are out of the while loop as the condition didnt match

        // so what can we do to handle this case

        // first make a function which checks if there is a loop or not
        // if not you found the base case
        // and if found make another function or make changes in the previous function to return the fast pointer with the slow pointer pointing to the head]
        // or else if found then we could be sure of using this code

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }

    Node *removeLoop(Node * &head)
    {
        if (head == NULL)
        {
            cout << "LL is empty " << endl;
            return NULL;
        }

        Node *slow = head;
        Node *fast = head;

        // again first check wheter there is actually loop or not

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }

            if (slow == fast)
            {
                slow = head;
                break;
            }
        }

        Node *prev = fast;
        while (slow != fast)
        {
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = NULL;

        // doubt is why are we returning the slow pointer
        return slow;
    }

    int main()
    {
        Node *head = new Node(10);
        Node *second = new Node(20);
        Node *third = new Node(30);
        Node *fourth = new Node(40);
        Node *fifth = new Node(50);
        Node *sixth = new Node(60);
        Node *seventh = new Node(70);
        Node *eighth = new Node(80);
        Node *ninth = new Node(90);
        head->next = second;
        second->next = third;
        third->next = fourth;
        fourth->next = fifth;
        fifth->next = sixth;
        sixth->next = seventh;
        seventh->next = eighth;
        eighth->next = ninth;
        ninth->next = fourth;

        // print(head);
        //   head = reverseKNodes(head, 5);
        //   print(head);

        // cout << "Middle Node is: " << getMiddle(head) -> data << endl;

        cout << "Loop is Present or not " << checkForLoop(head) << endl;
        cout << "Starting Point of LOOP is: " << startingPointLoop(head)->data << endl;
        removeLoop(head);
        print(head);
        cout << "Loop is Present or not " << checkForLoop(head) << endl;

        return 0;
    }

    // note: do the class 2 codes before tricky questions of class 1 so as to get a better understanding
    // of concepts used in linked list

    //  class 2

#include <iostream>
    using namespace std;

    class Node
    {
    public:
        int data;
        Node *next;

        Node()
        {
            this->data = 0;
            this->next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }

        // TODO: Write a destrcutor to delete a node
        // this is a very important todo which i need to explore and exploit both at the same time
        ~Node()
        {
            // write your code here
            cout << "Node with value: " << this->data << "deleted" << endl;
        }
    };

    // I want to insert a node right at the head of Linked List
    // linked list is just like a language just keep your basics rioght and focus on
    // problem solving rest can follow easily

    // so lets break down into simple language what does
    // insertathead means no its not what you are thinking

    // its like you create  a new node and point the pointer to the head of the linked list
    // and update the head pointer to the newly added node as it will become the head now
    void insertAtHead(Node * &head, Node * &tail, int data)
    {
        // check for Empty LL
        if (head == NULL)
        {
            Node *newNode = new Node(data);
            head = newNode;
            tail = newNode;
        }
        else
        {
            // step1:
            Node *newNode = new Node(data);
            // step2:
            newNode->next = head;
            // step3:
            head = newNode;
        }
    }
    // I want to insert a node right at the end of LINKED LIST

    // same goes for inserting at the tail
    // what we do is we will create a new node and then we will just
    // point the pointer of out tail to the new nide and then update the tail !!
    void insertAtTail(Node * &head, Node * &tail, int data)
    {
        if (head == NULL)
        {
            Node *newNode = new Node(data);
            head = newNode;
            tail = newNode;
            return;
        }
        // step1: creatae a node
        Node *newNode = new Node(data);
        // step2: connect woth tail ndoe
        tail->next = newNode;
        // step3: update tail;
        tail = newNode;
    }
    void print(Node * head)
    {

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    int findLength(Node * &head)
    {
        int len = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            len++;
        }
        return len;
    }

    // NOTE: indert at position is one of the most important topic that has basics on point

    // its like think a series of boxes are connected and wht you want is
    // to put one of the box in a position

    // so basic thing you need to break the connection at that point and then build the new connection

    // now what i can do is that i can go to the just prev position and will keep the
    // hold of the next node into account and then
    // will point its pointer to the newly created node and the pointer of newly created node
    // will be pointing towards the temporarily stored ponter

    void insertAtPosition(int data, int position, Node *&head, Node *&tail)
    {
        if (head == NULL)
        {
            Node *newNode = new Node(data);
            head = newNode;
            tail = newNode;
            return;
        }
        // step1: find the position: prev & curr;

        if (position == 0)
        {
            insertAtHead(head, tail, data);
            return;
        }

        int len = findLength(head);

        if (position >= len)
        {
            insertAtTail(head, tail, data);
            return;
        }

        // ste1:find prev and curr
        int i = 1;
        Node *prev = head;
        while (i < position)
        {
            prev = prev->next;
            i++;
        }
        Node *curr = prev->next;

        // DOUBT + INTERVIEW QUES: why did we do step 2 before step 3 dont go with number i am
        // talking about the lofgic

        // step2;
        Node *newNode = new Node(data);

        // step3:
        newNode->next = curr;

        // step4:
        prev->next = newNode;
    }

    void deleteNode(int position, Node *&head, Node *&tail)
    {
        if (head == NULL)
        {
            cout << "Cannot delete, LL is empty";
            return;
        }

        // deleting first node
        if (position == 1)
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return;
        }
        int len = findLength(head);

        // deleting last node
        if (position == len)
        {
            // find prev
            int i = 1;
            Node *prev = head;
            while (i < position - 1)
            {
                prev = prev->next;
                i++;
            }
            // step2:
            prev->next = NULL;
            // step3:
            Node *temp = tail;
            // step4:
            tail = prev;
            // step5:
            delete temp;
            return;
        }

        // deleting middle node

        // step  : find prev and curr
        int i = 1;
        Node *prev = head;
        while (i < position - 1)
        {
            prev = prev->next;
            i++;
        }
        Node *curr = prev->next;

        // step2:
        prev->next = curr->next;
        // step3:
        curr->next = NULL;
        // step4:
        delete curr;
    }

    // reversing the linked list is also one of the most basic and fucking important question of
    // linked list

    Node *reverse(Node * &prev, Node * &curr)
    {
        // base case
        if (curr == NULL)
        {
            // LL reverse ho
            //  this below statement wll return the prev as the head of the newly reversed linked list
            //  and what it is how it is dry run it to find more answer
            return prev;
        }

        // 1 case solve then recursion will take care
        //  vreating  a forward pointer so that we can pass that as current in the next iteration
        Node *forward = curr->next;
        curr->next = prev;

        reverse(curr, forward);
    }

    

    Node *reverseusingLoop(Node * head)
    {
        Node *prev = NULL;
        Node *curr = head;

        while (curr != NULL)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    Node *reverseusingRecursion(Node * prev, Node * curr)
    {
        // base case
        if (curr == NULL)
            return prev;

        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;

        // recursion sambhal lega
        return reverseusingRecursion(prev, curr);
    }
    int main()
    {

        Node *head = NULL;
        Node *tail = NULL;
        insertAtHead(head, tail, 20);
        insertAtHead(head, tail, 50);
        insertAtHead(head, tail, 60);
        insertAtHead(head, tail, 90);
        insertAtTail(head, tail, 77);

        print(head);
        cout << endl;
        // cout << "head: " << head -> data << endl;
        // cout << "tail: " << tail->data << endl;

        // insertAtPosition(101, 5, head, tail);
        // cout<< "Printing after insert at position call" << endl;
        // print(head);
        // cout << endl;
        // cout << "head: " << head -> data << endl;
        // cout << "tail: " << tail->data << endl;

        // deleteNode(9, head, tail);
        // cout << endl;
        // print(head);
        cout << endl;

        Node *prev = NULL;
        Node *curr = head;
        cout << "printing reverse list" << endl;
        head = reverseusingRecursion(prev, curr);
        cout << endl;
        print(head);
        cout << endl;

        return 0;
    }

    // class 4

    // the question is sum of 2 linked list !

    // lets discuss the algo/logic behind the problem
    //  what we did is we reversed both the linked list which is to be added .. and then we have applied
    //  our addition wala logic ..which consists of that carry wala lafda !

    // and at last what we did is we have reversed the answer to get the desired answer that we wanted !

#include <iostream>
    using namespace std;

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
    };

    void print(Node * head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    Node *reverse(Node * head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = curr->next;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node *solve(Node * &head1, Node * &head2)
    {

        if (head1 == NULL)
            return head2;
        if (head2 == NULL)
            return head1;

        // step1 : reverse both linked list
        head1 = reverse(head1);
        head2 = reverse(head2);

        // step2: add both linked list
        Node *ansHead = NULL;
        Node *ansTail = NULL;
        int carry = 0;

        while (head1 != NULL && head2 != NULL)
        {
            // calculate sum
            int sum = carry + head1->data + head2->data;
            // find digit to create node for
            int digit = sum % 10;
            // calculate carry
            carry = sum / 10;

            // create a new Node for the digit
            Node *newNode = new Node(digit);
            // attach the newNode into the answer wali linked list
            if (ansHead == NULL)
            {
                // first node insert krre ho
                ansHead = newNode;
                ansTail = newNode;
            }
            else
            {
                ansTail->next = newNode;
                ansTail = newNode;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // jab head1 list ki length head2 list se jada hogi
        while (head1 != NULL)
        {
            int sum = carry + head1->data;
            int digit = sum % 10;
            carry = sum / 10;
            Node *newNode = new Node(digit);
            ansTail->next = newNode;
            ansTail = newNode;
            head1 = head1->next;
        }

        // jab head2 list ki length head1 list se jada hogi
        while (head2 != NULL)
        {
            int sum = carry + head2->data;
            int digit = sum % 10;
            carry = sum / 10;
            Node *newNode = new Node(digit);
            ansTail->next = newNode;
            ansTail = newNode;
            head2 = head2->next;
        }

        // handle carry ko alag se
        while (carry != 0)
        {
            int sum = carry;
            int digit = sum % 10;
            carry = sum / 10;
            Node *newNode = new Node(digit);
            ansTail->next = newNode;
            ansTail = newNode;
        }

        // step3: reverse the ans linked list
        ansHead = reverse(ansHead);
        return ansHead;
    }

    int main()
    {
        Node *head1 = new Node(9);
        Node *second1 = new Node(9);
        head1->next = second1;

        Node *head2 = new Node(9);
        Node *second2 = new Node(9);
        // Node* third2 = new Node(4);
        head2->next = second2;
        // second2 -> next = third2;

        Node *ans = solve(head1, head2);

        print(ans);

        return 0;
    }

    // the question is check whether the linked list is palindrome or not !!!

    // the algorithm or the logic behind to solve the problem is that we go to the middle of the
    // linked list and then we reverse the linked list after the middle point and then we
    // point two pointers one at the first node and the other is at the node after the middle point !
    // and then we check for the similarity and if not found we return false and if found similar throughout
    // we return true !

#include <iostream>
    using namespace std;

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
    };

    Node *reverse(Node * head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = curr->next;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool checkPalindrome(Node * &head)
    {
        if (head == NULL)
        {
            cout << "LL is empty" << endl;
            return true;
        }
        if (head->next == NULL)
        {
            // only 1 node
            return true;
        }

        // >1 node in LL

        // StepA: find the middle node;
        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        // slow pointer is pointing to the middle node

        // Step B: reverse LL after middle/slow node
        Node *reverseLLKaHead = reverse(slow->next);
        // join the reversed LL into the left part
        slow->next = reverseLLKaHead;

        // Step C: start comparison
        Node *temp1 = head;
        Node *temp2 = reverseLLKaHead;
        while (temp2 != NULL)
        {
            if (temp1->data != temp2->data)
            {
                // not a palindome
                return false;
            }
            else
            {
                // if data is equal, then aage badh jao
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return true;
    }

    int main()
    {
        Node *head = new Node(10);
        Node *second = new Node(20);
        Node *third = new Node(30);
        Node *fourth = new Node(30);
        Node *fifth = new Node(20);
        Node *sixth = new Node(10);
        head->next = second;
        second->next = third;
        third->next = fourth;
        fourth->next = fifth;
        fifth->next = sixth;

        bool isPalindrome = checkPalindrome(head);

        if (isPalindrome)
        {
            cout << "LL is a valid palindrome" << endl;
        }
        else
        {
            cout << "LL is not a palindrome" << endl;
        }

        return 0;
    }

    // the question is remove duplicates from a sorted linked list !!!

    // but the main thing is try to remove duplicates from a unsorted linked list ...
    // there is 3 ways for this 1.nested loop
    // 2.sort and prev logic
    // 3.map

#include <iostream>
    using namespace std;

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
    };

    void print(Node * head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void removeDuplicates(Node * &head)
    {
        if (head == NULL)
        {
            cout << "LL is empty" << endl;
            return;
        }
        if (head->next == NULL)
        {
            cout << "Single Node in LL" << endl;
            return;
        }

        // >1 node in LL
        Node *curr = head;

        while (curr != NULL)
        {
            if ((curr->next != NULL) && (curr->data == curr->next->data))
            {
                // equal
                Node *temp = curr->next;
                curr->next = curr->next->next;
                // delete node
                temp->next = NULL;
                delete temp;
            }
            else
            {
                // not equal
                curr = curr->next;
            }
        }
    }

    int main()
    {

        Node *head = new Node(1);
        Node *second = new Node(2);
        Node *third = new Node(2);
        Node *fourth = new Node(3);
        Node *fifth = new Node(4);
        Node *sixth = new Node(4);
        head->next = second;
        second->next = third;
        third->next = fourth;
        fourth->next = fifth;
        fifth->next = sixth;

        cout << "input LL: ";
        print(head);

        removeDuplicates(head);
        cout << "output LL: ";
        print(head);

        return 0;
    }

    // the question is to sort the linked list 0s 1s and 2s!!!

#include <iostream>
    using namespace std;

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
    };

    void print(Node * head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void sortZeroOneTwo(Node * &head)
    {
        // step1: find count of zeroes, ones and twos
        int zero = 0;
        int one = 0;
        int two = 0;

        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == 0)
                zero++;
            else if (temp->data == 1)
                one++;
            else if (temp->data == 2)
                two++;
            temp = temp->next;
        }

        // step2: fill 0, 1 and 2s in the original ll
        temp = head;
        // fill zeroes
        while (zero--)
        {
            temp->data = 0;
            temp = temp->next;
        }

        // fill ones
        while (one--)
        {
            temp->data = 1;
            temp = temp->next;
        }

        // fill 2s
        while (two--)
        {
            temp->data = 2;
            temp = temp->next;
        }
    }

    Node *sort2(Node * &head)
    {
        if (head == NULL)
        {
            cout << "LL is empty " << endl;
            return NULL;
        }
        if (head->next == NULL)
        {
            // sngle node in LL
            return head;
        }

        // create dummy nodes
        Node *zeroHead = new Node(-101);
        Node *zeroTail = zeroHead;

        Node *oneHead = new Node(-101);
        Node *oneTail = oneHead;

        Node *twoHead = new Node(-101);
        Node *twoTail = twoHead;

        // traverse the original LL
        Node *curr = head;
        while (curr != NULL)
        {

            if (curr->data == 0)
            {
                // take out the zero wali node
                Node *temp = curr;
                curr = curr->next;
                temp->next = NULL;

                // append the zero node in zeroHead LL
                zeroTail->next = temp;
                zeroTail = temp;
            }
            else if (curr->data == 1)
            {
                // take out the one wali node
                Node *temp = curr;
                curr = curr->next;
                temp->next = NULL;

                // append the zero node in zeroHead LL
                oneTail->next = temp;
                oneTail = temp;
            }
            else if (curr->data == 2)
            {
                // take out the zero wali node
                Node *temp = curr;
                curr = curr->next;
                temp->next = NULL;

                // append the zero node in zeroHead LL
                twoTail->next = temp;
                twoTail = temp;
            }
        }

        // ab yha pr, zero , one, two, teeno LL readyv h

        // join them
        // remove dummmy nodes

        // modify one wali list
        Node *temp = oneHead;
        oneHead = oneHead->next;
        temp->next = NULL;
        delete temp;

        // modify two wali list
        temp = twoHead;
        twoHead = twoHead->next;
        temp->next = NULL;
        delete temp;

        // join list
        if (oneHead != NULL)
        {
            // one wali list is non empty
            // zero wali list ko one wali list se attach krdia
            zeroTail->next = oneHead;

            if (twoHead != NULL)
                oneTail->next = twoHead;
        }
        else
        {
            // one wali list is empty
            if (twoHead != NULL)
                zeroTail->next = twoHead;
        }

        // remove zerohead dummy Node
        temp = zeroHead;
        zeroHead = zeroHead->next;
        temp->next = NULL;
        delete temp;

        // return head of the modified linked list
        return zeroHead;
    }

    int main()
    {
        Node *head = new Node(2);
        Node *second = new Node(2);
        Node *third = new Node(1);
        Node *fourth = new Node(1);
        Node *fifth = new Node(0);
        Node *sixth = new Node(0);
        head->next = second;
        second->next = third;
        third->next = fourth;
        fourth->next = fifth;
        fifth->next = sixth;

        cout << "input LL: ";
        print(head);

        //   sortZeroOneTwo(head);
        //   print(head);

        cout << "printing the sorted list " << endl;
        Node *temp = NULL;
        head = sort2(head);
        // cout << "Came out of sort function" << endl;
        print(head);

        return 0;
    }