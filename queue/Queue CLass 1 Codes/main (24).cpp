// now queue is something which follows the first in first out order(fifo)
// what it means is that we will have two pointers which wil be front and rear respectively
// with the front we have the chance to access the front element and also to pop it out

// now  queue has different forms which possess some different characteristics!!
#include <iostream>
using namespace std;

// queue implementation with the help of array !!

class Queue
{
public:
        int *arr; // creating a dynamic array of integers which will store the elements of queue!!
        int size;
        int front; // pointer to the front !!
        int rear;  // pointer to the rear !!

        Queue(int size)
        { // this is the constructor
                this->size = size;
                arr = new int[size]; // creating the array with the help of dynamic memory allocation
                front = 0;           // seting the pointer to its initial loation to be 0
                rear = 0;            // same here as in front pointer
        }

        // functions or methods !!
// push hamesha rear se hoga so idhar reaar pe insert karke rear increment karna padega !!
        void push(int data)
        {
                if (rear == size) //it means that the queue is full 
                { // we didnt do rear =size-1 as because we first assign
                  // value in the rear position and then increment the pointer
                        cout << "Q is full " << endl;
                }
                else
                {
                        arr[rear] = data;
                        rear++;
                }
        }

        void pop()
        {
                if (front == rear)//it means the queue is emoty and there is nothing to pop
                {
                        cout << "Q is empty" << endl;
                }
                else
                {
                        arr[front] = -1;
                        front++;
                        if (front == rear)
                        { // making space utilization as if the queue is empty
                                // and both the pointers are in the non zero position and thus returning back to the initial position !!
                                front = 0;
                                rear = 0;
                        }
                }
        }

        int getFront()
        {
                if (front == rear)
                {
                        cout << "Q is empty" << endl;
                        return -1;
                }
                else
                {
                        return arr[front];
                }
        }

        bool isEmpty()
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

        int getSize()
        {
                return rear - front;
        }
};

int main()
{
        Queue q(10);

        q.push(5);
        q.push(15);
        q.push(25);
        q.push(55);

        cout << "Size of queue is: " << q.getSize() << endl;

        q.pop();

        cout << "Size of queue is: " << q.getSize() << endl;

        cout << "Front element is: " << q.getFront() << endl;

        if (q.isEmpty())
        {
                cout << "Q is empty" << endl;
        }
        else
        {
                cout << "Q is not empty" << endl;
        }

        return 0;
}