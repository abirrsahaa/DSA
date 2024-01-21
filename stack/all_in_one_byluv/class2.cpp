// the question is to take the top element of the stack and insert it in the bottom of the stack!!

// the logic here is the important pattern where we use reccurssion and keep a hold of the top element in the main functkion itself
// while in the function we reccursively remove each element and keeping the track of the top element in every call
// and when the stack is empty we push in the top element in the main and the rest of the elements we push through backtracking!!!

// this approach of using reccursion in stack is one of the ways how we can traverse in
// the stack with reference to size and keep a hold of the initial consn of the stack

#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int target)
{

    // base case
    if (s.empty())
    {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();
    // rec cal
    insertAtBottom(s, target);
    // BT
    s.push(topElement);
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

    if (s.empty())
    {
        cout << "stack is empty, cant insert at bottom" << endl;
        return 0;
    }

    int target = s.top();
    s.pop();
    insertAtBottom(s, target);

    cout << "Printing" << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}

// the question is to reverse a stack !!
// and the way is simple previous logic and pattern of reccurssion!!

// another way to use recurssion in stack not only to keep a hold of the initial stack
// but also to reverse the entire stack without any exta space !!

#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int target)
{

    // base case
    if (s.empty())
    {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();
    // rec cal
    insertAtBottom(s, target);
    // BT
    s.push(topElement);
}

void reverseStack(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }

    int target = s.top();
    s.pop();

    // reverse stack
    reverseStack(s);
    // insert at bottom target ko
    insertAtBottom(s, target);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    reverseStack(s);

    cout << "Printing" << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}

// the question is to sort the stack !!

// the question is besttttt has a number of appliations to derice from it

// we realised
// 1.we can insert an element in  a stack in an sorted manner
// 2.and obviously we now know how to sort a stack !!

// the approach and logic here ...do find out!!!

#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &s, int target) // ai function da diya ashole sorting hoitase !!
{
    // base case
    if (s.empty())
    {
        s.push(target);
        return;
    }
    if (s.top() >= target)
    {
        s.push(target);
        return;
    }

    // aikhane tokhon e aibo jokhon base case hit korse na
    // tar mane ki s.top() hoilo choto target r tika tar mane akhon target the stack
    // r baire lagar bodole bhitre konokhane lagbo

    int topElement = s.top();
    s.pop();
    insertSorted(s, target);

    // BT

    // bt tokhon e kaj korbo jokhon kono operation e base case hit korse na and
    // amar oibhabe abar stack the restructure korte lagdase
    s.push(topElement);
}

void sortStack(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }

    int topElement = s.top();
    s.pop();

    sortStack(s); // recurssion call kortase aikhane

    insertSorted(s, topElement);
}

int main()
{
    stack<int> s;
    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);

    sortStack(s);

    cout << "Printing" << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}

// this is a leetcode problem
// the problem mayne called the valid paranthesis problem ..its an important problem and pattern
// where we handle this brackets and paranthesis problem with the help of stack !!!

// very very important need to find proper logic behind this problem !!
class Solution
{
public:
    bool isValid(string s)
    {

        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            // opening bracket
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                // closing bracket - ch
                if (!st.empty())
                {
                    char topCh = st.top();
                    if (ch == ')' && topCh == '(')
                    {
                        // matching brackets
                        st.pop();
                    }
                    else if (ch == '}' && topCh == '{')
                    {
                        // matching brackets
                        st.pop();
                    }
                    else if (ch == ']' && topCh == '[')
                    {
                        // matching brackets
                        st.pop();
                    }
                    else
                    {
                        // brackets not matching
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }

        if (st.empty())
        {
            // valid
            return true;
        }
        else
        {
            return false;
        }
    }
};

// hoemework question was to remove redundant parenthesis ..
// we can search this question in leetcode for the solution
