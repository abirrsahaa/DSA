#include <iostream>
using namespace std;
int main()
{
    int arr1[6] = {1, 2, 3, 4, 5, 6};
    int arr2[5] = {5, 4, 3, 2, 1};
    // int d = arr1.size();
    // cout << d;
    int ans = 0;
    for (int i = 0; i < 6; i++)
    {
        ans = ans ^ arr1[i];
    }
    for (int i = 0; i < 5; i++)
    {
        ans = ans ^ arr2[i];
    }
    cout << "the missing element in the duplicates is : " << ans;
}