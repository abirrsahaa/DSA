#include <iostream>
using namespace std;
void bubble(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << "i returned at round no " << i + 1 << endl;
            return;
        }
    }
}
int main()
{
    int arr[6] = {10, 1, 7, 6, 14, 9};
    int n = 6;
    cout << "printing the initial array before sorting :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    bubble(arr, n);
    cout << "printing the final array after sorting :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}