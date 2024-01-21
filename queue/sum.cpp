#include <bits/stdc++.h>
using namespace std;

void palindrome(int n)
{
    int temp = n;
    int sum = 0;
    int dummy = 0;

    while (temp != 0)
    {
        int d = temp % 10;
        sum += d;
        dummy = dummy * 10 + d;
        temp = temp / 10;
    }

    cout << "the sum of the digits is --> " << sum << endl;

    if (dummy == n)
    {
        cout << "it is a palindrome number " << endl;
    }
    else
    {
        cout << "it is not a palindrome number " << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        palindrome(arr[i]);
    }
}