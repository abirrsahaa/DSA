// august 26 cipher school day 1
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int arr[100];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    int r;
    cin >> r;
    int z = num - r;
    for (int i = z - 1; i < num; i++)
    {
        cout << arr[i] << " ";
    }
    for (int i = 0; i < z - 1; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}