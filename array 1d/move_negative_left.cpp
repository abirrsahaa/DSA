#include <iostream>
using namespace std;
void move(int arr[], int n)
{
    // so basically its  about finding the negative elemenrs ans bringing them in the front
    // we will be using he two pointer approach as we need to keep a check whether the initial elements remain
    // negative or not
    int start = 0;
    int end = n - 1;
    // setting up my conditions

    while (start <= end)
    {

        if (arr[start] > 0 && arr[end] < 0)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }

        if (arr[start] > 0 && arr[end] > 0)
        {
            // swap(arr[start],arr[end]);
            // start++;
            end--;
        }

        if (arr[start] < 0 && arr[end] < 0)
        {
            swap(arr[start], arr[end]);
            start++;
            // end--;
        }

        if (arr[start] < 0 && arr[end] > 0)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
}
int main()
{

    int arr[6] = {1, 2, -3, 4, -5, 6};
    int n = 6;
    cout << "printing the array initially" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    move(arr, n);
    cout << "printing the array after swapping" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}