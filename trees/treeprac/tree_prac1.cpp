// this is the way abir saha studies and this is when i have decided
// to take the game to the next level to learn by getting my fucking hands dirty on the keyboard

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// creating class for nodes of a binary tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    Node()
    {
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }
};

// now it is obvious that once  i have created the nodes of the tree i know need to create the
// bigger thing that is the tree

Node *buildtree()
{
    // first i need to take the data
    // then create the root node
    // and then pass the same function to create the same thing for the left and the right part
    cout << "enter the data that would be taken to make the root:" << endl;
    int data;
    cin >> data;
    // the only base case i have in mind is that how to create the leaf node
    if (data == -1)
    {
        return NULL;
    }

    // now we have only three things to do one is to create the root node with the
    // data that we have received and the next is to do the same things with the
    // left and right part of the root node

    Node *root = new Node(data);

    cout << "enter the data to the left of " << data << "node :" << endl;
    root->left = buildtree();

    cout << "enter the data to the right of " << data << "node :" << endl;
    root->right = buildtree();

    return root;
}

// now its obvius that i have created the node and the entire tree tbh ..
// now the thing is whats the point if even after all this creation
// i am still not able to view the tree or the nodes of the tree

// the thing now is :
// to display the nodes of the tree we need to traverse the entire tree
// and to do that we have three ways to do this as of my knowledge as a noob

// level order traversal
// inorder traversal
// preorder traversal
// postorder traversal

// understand the pattern in which the question is solved
void levelordertraversal(Node *&root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        // this i am doing to print level wise in different line

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // this is a valid node which has data to be printed
            cout << temp->data << " ";

            // now that i have printed the node lets push its children to the queue so that they can be printed serially
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

// understanding the inorder traversal
// where we need to print the left node first and then the root node and then the right node

void inordertraversal(Node *root)
{

    // this is a reccursive traversal

    // base case
    if (root == NULL)
    {
        return;
    }

    // inorder traversal lnr
    inordertraversal(root->left);
    cout << root->data << " ";
    inordertraversal(root->right);
}

// now lets come to the preorder traversal where we will follow the nlr order
void preordertraversal(Node *root)
{
    // base case is same
    if (root == NULL)
    {
        return;
    }

    // the order in which we will traverse and print
    cout << root->data << " ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}

// now lets come to the postorder traversal where we will be following the lrn order
void postordertraversal(Node *root)
{
    // base case remains the same
    if (root == NULL)
    {
        return;
    }

    postordertraversal(root->left);
    postordertraversal(root->right);
    cout << root->data << " ";
}

// now lets find the height of the tree
// as its height it will return a integer
int height(Node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    // find me the height of the left part and the right part
    int leftpartheight = 1 + height(root->left);
    int rightpartheight = 1 + height(root->right);

    int ans = max(leftpartheight, rightpartheight);
    return ans;
}

// int height(Node *root)
// {
//     if (root == NULL)
//         return 0;

//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);
//     int ans = max(leftHeight, rightHeight) + 1; // why plus 1 here
//     return ans;
// }

// let the target sum  be 150
void solve(Node *root, int &currsum, int &targetsum, vector<int> &get, vector<vector<int>> &ans)
{
    // algo kita koi
    // ami root node da re array te push kortasi ,
    // sum update kortasi
    // reccursive call koira ditasi left r right part r liga

    // base case kita hoite pare
    // akta toh jokhon root node amar null hoibo direct return
    // akta jokhon amar sum 0 hoiya jaibo tokhon abar ans e push korte lagbo
    // sum kintu by reference jaibo
    // arekta hoise jokhon amar sum -1 hoiya jaibo

    if (root == NULL)
    {
        return;
    }
    if (currsum > targetsum)
    {
        return;
    }
    if (currsum == targetsum)
    {
        ans.push_back(get);
        // get.pop_back();
        // currsum -= root->data;
        return;
    }

    // aikhane aisi mane amar base case aktao hit hoise na
    // tar mane ami amar root loiya darai asi
    get.push_back(root->data);
    currsum += root->data;
    // reccursive call koira disi
    solve(root->left, currsum, targetsum, get, ans);
    solve(root->right, currsum, targetsum, get, ans);

    // aikhane aisi mane amar base case hit hoise tar mane amar backtrack korte lagbo
    get.pop_back();
    currsum -= root->data;
    // return;
}

// the problem statement says to find the lowest common ancestor or what
// is abbrevated as LCA
// here we would be given 2 nodes and the concept says whereever we find a node
// where both the nodes point first starting from bottom is our LCA

Node *finding(Node *&p, Node *&q, Node *root)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == p->data)
    {
        return p;
    }
    if (root->data == q->data)
    {
        return q;
    }

    Node *leftans = finding(p, q, root->left);
    Node *rightans = finding(p, q, root->right);

    // cases
    // duno jagar tika amar kase NULL aise
    // ak jaga tika null aise arek jagay tika p ba q aise
    // amar dono jaga tika ans aise
    if (leftans == NULL & rightans == NULL)
    {
        return NULL;
    }
    else if (leftans != NULL && rightans == NULL)
    {
        return leftans;
    }
    else if (leftans == NULL && rightans != NULL)
    {
        return rightans;
    }
    else
    {
        return root;
    }
}

// to find the sum of the longest blood line
void finding(Node *root, vector<int> &temp, vector<vector<int>> &ans)
{
    cout << "i am in the finding function" << endl;
    // base case
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(temp);
        return;
    }
    if (root == NULL)
    {
        return;
    }

    temp.push_back(root->data);
    finding(root->left, temp, ans);
    finding(root->right, temp, ans);

    // backtrack
    temp.pop_back();
    return;
}

int sumlongest(Node *root)
{
    cout << "i am inside the longest sum function" << endl;

    vector<int> temp;
    vector<vector<int>> final;
    vector<vector<int>> ans;
    finding(root, temp, ans);

    cout << "i came back from sum longest function" << endl;

    //   base case
    if (ans.size() == 0)
    {
        return 0;
    }
    else
    {
        // int index=0;
        int size = -1;

        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i].size() > size)
            {
                // aikahne duita case lagte pare jeta amar alada koira samlaite lagbo !
                size = ans[i].size();
            }
        }

        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i].size() == size)
            {
                final.push_back(ans[i]);
            }
        }

        // if(final.size()==1){

        // }
        // else{
        int sum = -1;
        int sumn;
        int index = -1;
        for (int i = 0; i < final.size(); i++)
        {
            for (int j = 0; j < final[i].size(); j++)
            {
                sumn += final[i][j];
            }
            if (sumn > sum)
            {
                sum = sumn;
                index = i;
            }
        }
        return sum;
        // }
    }
}

int main()
{
    Node *root = buildtree();

    cout << "printing the tree that is formed right now ::" << endl;
    levelordertraversal(root);

    cout << "printing the maximum height of the tree :" << endl;
    cout << height(root) - 1 << endl;

    // why i have subtracted 1 ?
    // simple answer the base case is related to leaf node or when the root ia null i know they both are not same still you get it right
    // simple answer leaf node has 1 node and 0 edges ... with this being said we need to modify our answer according to this !!

    // as what we are doing is to increment we are adding the first edge by our own
    // which will fail if when it is the leaf node so to avoid that thing we are subtracting 1

    // we shouldnt have subtracted 1 if we have been asked to print the maximum depth in terms of nodes
    // as in the case of a leaf node the node count is 1 where as the edge count is zero

    // vector<int> get;
    // vector<vector<int>> ans;
    // int targetsum = 150;
    // int currsum = 0;
    // solve(root, currsum, targetsum, get, ans);

    // cout << "printing the path :" << endl;

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << "printing the longest sum :" << sumlongest(root) << endl;

    // Node *LC=finding()
}