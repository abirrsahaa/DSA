// implementing stack with the help of array by using class concept

// try to explore how to make stack using linked list too !!

#include <iostream>
using namespace std;

class Stack
{

private:
    int *arr; // why did i make a pointer here?
    int top;  // this is for the top most pointer
    int size;

public: // the public access specifier is public which means that these stuff could well possibly
    // be accessed outside this class
    Stack(int size) // this is a parameterised constructor !! which will be triggered each time a object
                    // of this class will be created !!
    {
        arr = new int[size]; // creating a array of integers which is going to store the elements of the stack
        this->size = size;   // the size to the left of the =  is the property size of the class
        // where the size to the right of = is a parameter passed
        top = -1; // specifying its an empty stack !!
    }

    // functions  or methods of the class !!

    void push(int data)
    {
        if (size - top > 1) // why size - top ?? consider a stack of size 3 and the top is at 1 then technicalyy
        // there is one space left as the last index is of 2 and moreover the result is 3-1=2 and the
        // consition being >1 its true !!
        // if the stack is empty there should be 3 spaces left and to have 3 spaces we should be having result 1+3=4
        // therefore lets see what is the result we obtain 3-(-1)=3+1=4 ..and thats how this conditiom stamds true !!
        {
            // space available
            // insert
            top++; // as first the top pointer is at the previous index which has an element
                   // and thus we need to first increment the pointer and then insert the value
            arr[top] = data;
        }
        else
        {
            // space not available
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() // pop doesnt return any element it just shifts the top pointer to the previous position !!
    {
        if (top == -1) // condition to check whether the stack is empty or not ??!
        {
            // stack is empty
            cout << "Stack underflow, cant delete element" << endl;
        }
        else
        {
            // stack is not empty
            top--;
        }
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "There is not element in Stack " << endl;
        }
        else
        {
            return arr[top];
        }
    }

    // return number of valid elements present in stack
    int getSize()
    {
        return top + 1; // as because top is nothing but the index of the topmost element !!
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    // CREATION
    Stack s(5);

    // insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    // s.push(60);

    while (!s.isEmpty())
    {
        cout << s.getTop() << " ";
        s.pop();
    }
    cout << endl;

    cout << "Size of stack " << s.getSize() << endl;

    s.pop();

    return 0;
}

// reverse a string using the stack !!

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "babbar";

    stack<char> s; // implementing the stl of stack !!
    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}

// the basic code for implementing stack and basic methods of stack !!
// basically using the stl of stack !!
#include <iostream>
#include <stack>
using namespace std;

int main()
{

    // creation
    //  stack<int> st;

    // //insertion
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);

    // //remove
    // st.pop();

    // //check element on top
    // cout << "Element on top is: " << st.top() << endl;

    // //size
    // cout << "size of stack is: " << st.size() << endl;

    // if(st.empty())
    //         cout << "stack is empty" << endl;
    // else
    //         cout << "stack is not empty" << endl;

    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}

// creating two stacks in an arrray
// the approach is the two pointer approach !! where one pointer goes forward and the other goes backward!

// one of the classic question of stack!!
#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    // functions
    void push1(int data)
    {
        if (top2 - top1 == 1)
        {
            // space not available
            cout << "OVERFLOW int stack 1" << endl;
        }
        else
        {
            // space available
            top1++;
            arr[top1] = data;
        }
    }

    void pop1()
    {
        if (top1 == -1)
        {
            // stack empty
            cout << "UNDERFLOW in stack 1" << endl;
        }
        else
        {
            // stack not empty
            arr[top1] = 0;
            top1--;
        }
    }

    void push2(int data)
    {
        if (top2 - top1 == 1)
        {
            // space not available
            cout << "OVERFLOW in stack 2" << endl;
        }
        else
        {
            top2--;
            arr[top2] = data;
        }
    }

    void pop2()
    {
        if (top2 == size)
        {
            // stack 2 is empty
            cout << "UNDERFLOW in stack 2" << endl;
        }
        else
        {
            // stack 2 is not empty
            arr[top2] = 0;
            top2++;
        }
    }

    void print()
    {
        cout << endl;
        cout << "top1: " << top1 << endl;
        cout << "top2: " << top2 << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s(10);

    s.push1(10);
    s.print();
    s.push1(20);
    s.print();
    s.push1(30);
    s.print();
    s.push1(40);
    s.print();
    s.push1(50);
    s.print();

    s.push2(100);
    s.print();
    s.push2(110);
    s.print();
    s.push2(120);
    s.print();
    s.push2(130);
    s.print();
    s.push2(140);
    s.print();

    s.pop1();
    s.print();
    s.pop1();
    s.print();

    s.pop1();
    s.print();

    s.pop1();
    s.print();

    s.pop1();
    s.print();

    s.push2(1000);
    s.print();

    s.pop1();
    s.print();
    return 0;
}

// print the middle element of the stack !!!

// the approach we used is reccurssion and what we do is we keep on removing one element from top
// from every single reccursive call until we reach the middle of the dtsck obtained from the initial size

// and why do we backtrack here just to get back the initial stack

#include <iostream>
#include <stack>
using namespace std;

void printMiddle(stack<int> &s, int &totalSize)
{
    if (s.size() == 0)
    {
        cout << "There is no element in stack" << endl;
        return;
    }
    // base case
    if (s.size() == totalSize / 2 + 1)
    {
        cout << "Middle element is: " << s.top() << endl;
        return;
    }

    int temp = s.top();
    s.pop();

    // recursive call
    printMiddle(s, totalSize);

    // backtrack;
    s.push(temp);
}

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    int totalSize = s.size();
    printMiddle(s, totalSize);

    return 0;
}