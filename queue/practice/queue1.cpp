// what we need to implement is the thing that we will make use the concept of oops
// and implement the fuctionaity of queue
// which follows a fifo ordering that is first in and first out
// in queue we will be having a front pointer and we will be having a rear poiunter
// the front pointer is mostly used to pop elements from the top
// where the rear pointer is to push the new elements bacm to the quue

// functionalities that we will be implementing in the basic queue
// push adding new element to the back of the queue
// pop removing element from the front of the queue
// isempty
// top  gets me the element which is first inserted
// size ---!!!
// number of elements in the queue --- front - rear

#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue() {}

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        this->front = 0;
        this->rear = 0;
    }

    // for pushing cases that i should keep in mind
    // is the queue empty
    // is the queue full
    void push(int element)
    {
        if (rear == size)
        {
            cout << "the queue is full" << endl;
            return;
        }
        else
        {

            arr[rear] = element;
            rear++;
        }
    }

    // handling the case when the queue is empty how to take out element
    void pop()
    {
        if (front == rear)
        {
            cout << "the queue is empty ~!!!!11" << endl;
            return;
        }
        else
        {
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int frontelement()
    {
        if (front == rear)
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isempty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int numberoflements()
    {
        if (front == rear)
        {
            return 0;
        }
        else
        {
            return abs(front - rear);
        }
    }
};

int main()
{
    Queue abir(10);
    abir.push(3);
    abir.push(4);
    abir.push(5);
    abir.push(6);
    abir.push(3);
    abir.push(4);
    abir.push(5);
    abir.push(6);
    abir.push(5);
    abir.push(6);
    abir.push(5);
    abir.push(6);

    cout << "printing the queue-->" << endl;
    while (!abir.isempty())
    {
        int top = abir.frontelement();
        abir.pop();
        cout << top << " ";
    }
    // cout << abir.isempty() << endl;
    if (abir.isempty() == 0)
    {
        cout << "unfortunately the queue is empty " << endl;
    }
}