// creating the tree

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

// now that node is created its time to create the binary treee

// as we will be needind the root of the tree to always access the tree
// that is the reason why we are making this function a return type of the class Node
Node *buildtree()
{
    int data;
    cout << "enter the value of the data :" << endl;
    cin >> data;

    if (data == -1)
        return NULL;

    Node *root = new Node(data);

    // now that my root node is created its time for me to create the other nodes of
    // the binary tree
    cout << "enter the data you want to enter to the left of " << data << endl;
    root->left = buildtree();

    cout << "enter the data you want to enter to the right of " << data << endl;
    root->right = buildtree();

    // now that i have created my entire tree its high time that i return the root of my tree
    return root;
}

// before starting with traversing why not get some taste of reccursion

// lets find the maximum depth of the tree
// maximum depth can be of two types one in terms of edges it has or in terms of nodes

// reccursive mindset i will be doing a single case and the rest will be taken care
// by the reccursion

int maxdepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = maxdepth(root->left);
    int right = maxdepth(root->right);
    return max(left, right) + 1;
}

// now lets do another variation of this question
// lets find the diameter of the tree
// it is the maximum depth between any two nodes which may or may not include the root

// now its simple as we have been said that the inclusion of root is not mandatory
// so the answer can lie in the tree in three possible regions
// either in the left of teh root
// either in the right of the root
// or including the right left and the root
// so what we will be doing is just find the height of the left of the root
// right of the root and then add the root and then find the maximum of it

// TODO: doubt in this diameter wala question

int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    // TODO: Find out why we used this function name in left and right

    int left = diameter(root->left);
    int right = diameter(root->right);
    int combine = left + right + 1;
    return max((left, right), combine);
}

// now its fine that i have created my binary tree now
// whats use of a binary tree along with the access of the root
// but we are not able to traverse so lets boil to down to all sorts of traversing

// inorder/preorder/postorder
// levelorder
// boundary
// zigzag
// diagonal

// lets start with basic traversal
//  inorder that is lnr

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // lnr
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // nlr
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // lrn
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// here comes one of the most important traversal that is
// levelorder traversal
// what i will be doing in level order traversal is first decide how will you move in the tree that is in which order
// for me what i would need is first the node as in kevel first the root node comes so preorder is the order that we need to follow

void levelordertraversal(Node *root)
{

    // TODO: listing the mistakes i did while coding this
    // !!! : taking queue of type int thinking i will play with values but i will fail in checking the base case of NULL as node is NULL not the data
    // !!!: second while pushing the NULL after getting NULL i didnt check whether the queue is empty or not as in that case it will be an infinite loop

    queue<int> p;
    p.push(root->data);
    p.push(NULL);
    while (!p.empty())

    {
        int value = p.front();
        p.pop();
        if (value == NULL)
        {
            cout << endl;
            // TODO: why did we push here NULL
            // As getting NULL signifies all the child elements have been pushed for that level so we
            // need to insert NULL to signify the end of the child level
            p.push(NULL);
        }
        else
        {
            cout << value << " ";
            if (root->left != NULL)
            {
                p.push(root->left->data);
            }
            if (root->right != NULL)
            {
                p.push(root->right->data);
            }
        }
    }

    // TODO: !!! correcting the above listed mistakes

    queue<Node *> p;
    if (root == NULL)
    {
        cout << "the tree dont exist" << endl;
        return;
    }
    p.push(root);
    p.push(NULL);

    while (!p.empty())
    {
        Node *temp = p.front();

        p.pop();

        if (temp == NULL)
        {
            cout << endl;
            // !!! this is the case which i missed handling this case is very much important
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                p.push(temp->left);
            }
            if (temp->right)
            {
                p.push(temp->right);
            }
        }
    }
}

// !!!!
// TODO:
// dekh bhai traversal abhi bhi 3 bache hai jo kki hai
// boundary zigzag aur tera diagonal
// dekh bhai bolne ko toh tera vertical ttraversal bhi baki hai


// !!!!!NEED TO GO THROUGH BOUNDARY TRAVERSAL FROM SCRATCH!!!!!!!!!

// !!DOING THE DIAGONAL TRAVERSAL 
// TODO:keeping some points in mind 
// ? how to play with leveling and in which logic 
// !MAIN LOGIC:[while going left we will increment the level but while going right the level will remain the same]
// !!MAIN NOTE :[frame your data structure acording to your logic]



void diagonal(Node* root,map<int,vector<int>>m,int level){
    if(root==NULL){
        return;
    }
    m[level].push_back(root->data);
    // right traverse e level same thakbo

    diagonal(root->right,m,level);

    // left traverse
    diagonal(root->left,m,level+1);
}








// par chal ab kuch view view khelte hai

// pehle its about top and bottom view
// obviously horizontal distance wala idea mera toh hai nahi
// but its a pattern which is to keep in mind
// root ko zero pakarna and right jao toh +1 and left jai o to -1
// abb yeh hai ke how will you manage the data
// !!! major thing structuring the data structure so to justify our logic
// !!! wait what is the logic here ???
// what we will be doing is that we will be doing level order traversal and keeping a track of
// the node and the hd and while we will be doing this when we will be checking this thing we will be having the node and its hd
// what we will do is now that we need only one value wwe will be keeping a map for it so that we have a specific value for each hd
// now on the basis of what we need wheter the first node in every hd or the last node we can structure our condition with respect to that

void topview(Node *root)
{
    // dekh bhai korum to level order traversak oii karon amar first the lagbo everylevel r level e gele oita hoibo ..
    // TODO: check koris bab bhabis toh kere preorder korsos na
    // !!! data structure define kor kemne ki kortasos
    // !!queue te store korte lagbo node r hd tare tahole
    // TODO:queue<pair<Node*,int>> pai data structure karon amar duita jinish aitate store korte lagbo
    // TODO:r hoise map<int,int> jeikhane data r hd thakbo and idai amar answer hoibo

    queue<pair<Node *, int>> q;
    map<int, int> m;

    // initial pushing for level order traversal
    if (root == NULL)
    {
        cout << "ki bal r top view tumar tree oi exist kore na " << endl;
        return;
    }
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        q.pop();
        Node *temp = p.first;
        int hd = p.second;

        // check korjen oi distance e r kisu ase ni
        if (m.find(hd) == m.end())
        {
            // tar mane nai r ki toile entry create koira dou
            m[hd] = temp->data;
        }
        // thakle toh kisu korte prtm na karon amar top view te first node ta e lgbo
        if (temp->left)
        {
            q.push(make_pair(temp->left, hd - 1));
        }

        if (temp->right)
        {
            q.push(make_pair(temp->right, hd + 1));
        }
    }
}

void bottomview(Node *root)
{
    // dekh bhai korum to level order traversak oii karon amar first the lagbo everylevel r level e gele oita hoibo ..
    // TODO: check koris bab bhabis toh kere preorder korsos na
    // !!! data structure define kor kemne ki kortasos
    // !!queue te store korte lagbo node r hd tare tahole
    // TODO:queue<pair<Node*,int>> pai data structure karon amar duita jinish aitate store korte lagbo
    // TODO:r hoise map<int,int> jeikhane data r hd thakbo and idai amar answer hoibo

    queue<pair<Node *, int>> q;
    map<int, int> m;

    // initial pushing for level order traversal
    if (root == NULL)
    {
        cout << "ki bal r top view tumar tree oi exist kore na " << endl;
        return;
    }
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        q.pop();
        Node *temp = p.first;
        int hd = p.second;

        // check korjen oi distance e r kisu ase ni
        if (m.find(hd) == m.end())
        {
            // tar mane nai r ki toile entry create koira dou
            m[hd] = temp->data;
        }
        // !!! here is the difference in the above code in top view we had to include only
        // !!! only the first node of each hd
        // !!! but in bottom view we would be in need of the last node in every hd
        if (temp->left)
        {
            q.push(make_pair(temp->left, hd - 1));
        }

        if (temp->right)
        {
            q.push(make_pair(temp->right, hd + 1));
        }
    }
}

// TODO:chlo ab Right view or Left view krte hai
// !!! karne ko toh bohot hai par in tariko se bhi dono try karna
// ?? levelordertraversal
// ??recursion and map or map solely
// ?or any other way you can think of

// !!NOW LETS do with the RECURSION METHOD
// !!!!keep in mind the following things

// ??! obviusly playing with level or hd(somewhat)
// ?? how we will be traversing (i.e in which order)
// TODO:  !!logic: [SAME LEVEL SHOULD HAVE SAME NUMBER OF ELEMENTS ONLY THEN WE WILL BE ENTERING A NEW ELEMENT]
// !! in what way (i.e either go for the right node first or the left node first depending on ehich view we will be working)

void rightview(Node *root, vector<int> ans, int level)
{
    if (root == NULL)
        return;

    // main condition
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    // right view right so pehle humko jana hoga right mai
    rightview(root->right, ans, level + 1);
    rightview(root->left, ans, level + 1);

    // !!!! here even without the return the code is working find out how
    // !! as i am generally someone who likes to visualize for me returning sounds good
    // !! but important is how does it work even without the return
    return;
}

void leftview(Node *root, vector<int> ans, int level)
{
    if (root == NULL)
        return;

    // main condition
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    // right view right so pehle humko jana hoga right mai
    leftview(root->left, ans, level + 1);
    leftview(root->right, ans, level + 1);

    // !!!! here even without the return the code is working find out how
    // !! as i am generally someone who likes to visualize for me returning sounds good
    // !! but important is how does it work even without the return
    return;
}




int main()
{
}