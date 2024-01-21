#include <iostream>
#include <stack>
using namespace std;

// so the problem states to reverse a string with the help of stack

void print(stack<int> &number, int size)
{
    // base case
    if (number.size() == 0)
    {
        return;
    }
    if (number.size() == size / 2 + 1)
    {
        cout << "printing the middle element of the stack is :" << endl;
        cout << number.top() << endl;
    }

    // logical part
    int top = number.top();
    number.pop();

    print(number, size);

    number.push(top);
}

// tasks for today in less than 30 mins

// every question that followed follows a specific pattern do keep this pattern in mind

// problem 1 - to put the first element of the stack to the last

// problem 2 - to reverse a stack

// problem 3- to sort a stack

void putting(stack<int> &number, int element)
{
    // base case
    if (number.empty())
    {
        number.push(element);
        return;
    }

    // not empty
    int temp = number.top();
    number.pop();

    // reccursive call
    putting(number, element);

    number.push(temp);
    return;
}

void reversing(stack<int> &number)
{
    // base case
    if (number.empty())
    {
        return;
    }

    // not empty
    int temp = number.top();
    number.pop();

    // reccursive call
    reversing(number);

    // backtrack
    putting(number, temp);
    return;
}

// so the problem statement states to  sort the stack
// so here also we will be needing two functions one which lets
// us traverse the whole stack and
// the other which actually sorts the stack with the elements we traversed

void sort(stack<int> &random, int element)
{
    cout << "i have hit the second func" << endl;

    // base case
    if (random.empty() || element >= random.top())
    {
        random.push(element);
        return;
    }

    // if (element >= random.top())
    // {
    //     random.push(element);
    //     return;
    // }

    // not following my sort function

    int temp = random.top();
    random.pop();

    // rc
    sort(random, element);

    // backtrack
    random.push(temp);
    // return;
}

void traversetosort(stack<int> &random)
{
    // base case
    if (random.empty())
    {
        cout << "i have reached the base case of first func" << endl;
        return;
    }

    // not empty
    int temp = random.top();
    random.pop();

    // rc
    traversetosort(random);

    // backtrack
    cout << "i am backtracking" << endl;
    sort(random, temp);
    // return;
}

int main()
{
    // string name = "abir";
    // stack<char> letter;
    // for (int i = 0; i < name.length(); i++)
    // {
    //     letter.push(name[i]);
    // }

    // // now that i have entered the name in the stack now if i print the stack
    // // the letter that had entered at the last will come first

    // cout << "printing the name in the reverse order :" << endl;

    // while (!letter.empty())
    // {
    //     cout << letter.top() << " ";
    //     letter.pop();
    // }

    // stack<int> number;

    // number.push(1);
    // number.push(2);
    // number.push(3);
    // number.push(4);
    // number.push(5);
    // number.push(6);
    // number.push(7);

    // print(number, number.size());

    // int element = number.top();
    // number.pop();

    // putting(number, element);

    // cout << "printing the stack after putting the first element of the stack to the last of the stack " << endl;
    // while (!number.empty())
    // {
    //     cout << number.top() << " ";
    //     number.pop();
    // }

    // reversing(number);
    // cout << "printing the stack after reversing:" << endl;
    // while (!number.empty())
    // {
    //     cout << number.top() << " ";
    //     number.pop();
    // }

    stack<int> random;
    random.push(10);
    random.push(60);
    random.push(2);
    random.push(3);
    random.push(90);
    random.push(1);
    random.push(55);

    cout << "printing the stack before i have sorted it :" << endl;
    while (!random.empty())
    {
        cout << random.top() << " ";
        random.pop();
    }

    cout << endl;

    traversetosort(random);

    cout << "printing the stack after i have sorted the stack :" << endl;
    while (!random.empty())
    {
        cout << random.top() << " ";
        random.pop();
    }
}

// now the problem statement is to print the middle element of the stack !