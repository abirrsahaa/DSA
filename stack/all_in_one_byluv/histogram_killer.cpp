// to find the previous greater element

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> v;
//     for (int i = 0; i < n; i++)
//     {
//         // cout << "for the index " << i << " ";
//         int element;
//         cin >> element;
//         v.push_back(element);
//     }
//     // cout << "i am out of loop";
//     // cout << v.size();

//     // now comes the logic part
//     stack<int> s;

//     // for the very first element
//     int count = 0;
//     int *ans = new int[n];
//     ans[count++] = -1;
//     s.push(0);

//     // for the remaining elements
//     for (int i = 1; i < v.size(); i++)
//     {
//         // comparing
//         // cout << "i am inside for loop for index " << i << endl;
//         while (s.empty() == false && v[s.top()] <= v[i])
//         {
//             s.pop();
//         }

//         // now that i am out of the loop lets definee some edge case s
//         if (s.empty())
//         {
//             ans[count++] = -1;
//             s.push(i);
//         }
//         else
//         {
//             ans[count++] = v[s.top()];
//             s.push(i);
//         }
//     }
//     // now that my answer is ready
//     cout << "printing the answer array" << endl;
//     for (int i = 0; i < count; i++)
//     {
//         cout << ans[i] << " ";
//     }
// }

// now to do it with the same lof=gic for the next greater element

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        // cout << "for the index " << i << " ";
        int element;
        cin >> element;
        v.push_back(element);
    }
    // cout << "i am out of loop";
    // cout << v.size();

    // now comes the logic part
    stack<int> s;

    // for the very first element
    int count = 0;
    // int *ans = new int[n];
    stack<int> ans;
    ans.push(-1);
    s.push(v.size() - 1);

    // for the remaining elements
    for (int i = v.size() - 2; i >= 0; i--)
    {
        // comparing
        // cout << "i am inside for loop for index " << i << endl;
        while (s.empty() == false && v[s.top()] <= v[i])
        {
            s.pop();
        }

        // now that i am out of the loop lets definee some edge case s
        if (s.empty())
        {
            // ans[count++] = -1;
            ans.push(-1);
            s.push(i);
        }
        else
        {
            // ans[count++] = v[s.top()];
            ans.push(v[s.top()]);
            s.push(i);
        }
    }
    // now that my answer is ready
    cout << "printing the answer array" << endl;
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << ans.empty() << endl;
    while (ans.empty() == false)
    {
        // cout << " i am inside while " << endl;
        cout << ans.top() << " ";
        ans.pop();
    }
}