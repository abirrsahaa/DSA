#include <bits/stdc++.h>
using namespace std;
class abir
{
public:
    string song;
    string author;
};
int main()
{
    cout << "enter the number of songs !!" << endl;
    int n;
    cin >> n;
    abir getting[100];
    for (int i = 1; i <= n; i++)
    {
        cout << "enter the name of the song " << endl;

        getline(cin, getting[i].song);
        cout << "enter the name of the auhtor " << endl;
        getline(cin, getting[i].author);
        cout << "i am inside --> " << getting[i].song << " " << getting[i].author << endl;
    }
    cout << "lets check the array before sorting ..!" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << getting[i].author << " " << getting[i].song << endl;
    }
    // now i have my inout array reday lets see hoe can i sort
    // sort(getting, getting + n, getting->author);

    // lets execute the logic for sorting
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n - 1; j++)
        {
            if (getting[j].author > getting[j + 1].author)
            {
                swap(getting[j], getting[j + 1]);
            }
        }
    }
    cout << "lets now check the array after sorting !!" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << getting[i].author << " " << getting[i].song << endl;
    }
    return 0;
}