#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildtree(node *root)
{

    cout << "enter data" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "inserting element in the left" << data << endl;
    root->left = buildtree(root->left);
    cout << "inserting element in the right" << data << endl;
    root->right == buildtree(root->right);
    return root;
}

void levelordertraversal(node *root)
{

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left)
        {
            q.push(temp->left);
        }

        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

int main()
{

    node *root = NULL;
    root = buildtree(root);
    levelordertraversal(root);
    return 0;
}
