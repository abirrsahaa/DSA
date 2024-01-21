// implementation of deque which is a special type of queue
// using the stl of c++
// deque is a queue where we can push and pop elements both from the front and the back !!

#include <iostream>
#include <deque>
using namespace std;

int main()
{
        // creation
        deque<int> dq;

        dq.push_front(5);
        dq.push_front(10);
        dq.push_back(20);
        dq.push_back(30);

        cout << "Size: " << dq.size() << endl;
        dq.pop_front();
        cout << "Size: " << dq.size() << endl;
        dq.pop_back();
        cout << "Size: " << dq.size() << endl;

        cout << "Front:  " << dq.front() << endl;
        cout << "back: " << dq.back() << endl;

        if (dq.empty())
        {
                cout << "DQ is empty" << endl;
        }
        else
        {
                cout << "DQ is not empty" << endl;
        }

        return 0;
}