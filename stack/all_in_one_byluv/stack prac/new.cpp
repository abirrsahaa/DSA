#include <iostream>
#include <stack>
using namespace std;

bool isvalid(string str)
{
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == '{' or ch == '[' or ch == '(')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty() and ch == ')' and st.top() == '(')
            {
                st.pop();
            }
            else if (!st.empty() and ch == '}' and st.top() == '{')
            {
                st.pop();
            }
            else if (!st.empty() and ch == ']' and st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main()
{
    string str = "(()){{}}";
    cout << isvalid(str) << endl;
    return 0;
}