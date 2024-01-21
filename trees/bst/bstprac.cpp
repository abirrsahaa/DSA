#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;

    Node(int data){
        this->data=data;
        right=NULL;
        left=NULL;
    }

};

Node* insertintobst(Node* root,int data){
    // base case
    if(root==NULL){
        // this is the very first data 
        root=new Node(data);
        return root;
    }

    // for bst there would be a condition
    if(data>=root->data){
        root->right=insertintobst(root->right,data);
    }
    else{
        root->left=insertintobst(root->left,data);
    }
    return root;
    
}

void takeinput(Node *&root){
 
    int data;
    cin>>data;
    while(data!=-1){
        root=insertintobst(root,data);
        cin>>data;
    }
}


// now the most important 3 traversals but easy
// pre inorder post
// the code for pre order which goes fpr nlr
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
// the code for inorder which goes for lnr
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
// the code for postorder which goes for lrn
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}





// now the code for searching in bst
Node* searchinbst(Node* root,int data){
    // base case
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
        return root;
    }
    if(data>root->data){
        return searchinbst(root->right,data);
    }
    else{
        return searchinbst(root->left,data);
    }
}

// now the code for finding the minimum value in bst
int minval(Node* root){
    Node* temp=root;
    if(temp==NULL){
        return -1;
    }
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}

// now the code for finding the maximum value in bst
int maxval(Node* root){
    Node* temp=root;
    if(temp==NULL){
        return -1;
    }
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
}

// now the code for deleting a node in bst
Node* deleteinbst(Node* root,int data){
    // base case
    if(root==NULL){
        return NULL;
    }
    if(data>root->data){
        root->right=deleteinbst(root->right,data);
        return root;
    }
    else if(data<root->data){
        root->left=deleteinbst(root->left,data);
        return root;
    }
    else{
        // now the case for 3 conditions
        // 1. when the node is a leaf node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // 2. when the node has only one child
        if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        // 3. when the node has 2 children
        // we will replace the node with the minimum value in the right subtree
        int rightmin=minval(root->right);
        root->data=rightmin;
        root->right=deleteinbst(root->right,rightmin);
        return root;
    }
}
int main(){

}

// c++ program to find factorial of a large number recusively
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[1000000];
    arr[0]=1;
    int len=1;
    int x=2;
    int num=0;
    int carry=0;
    while(x<=n){
        num=0;
        carry=0;
        while(num<len){
            arr[num]=arr[num]*x+carry;
            carry=arr[num]/10;
            arr[num]=arr[num]%10;
            num++;
        }
        while(carry!=0){
            arr[len]=carry%10;
            carry=carry/10;
            len++;
        }
        x++;
    }
    len--;
    while(len>=0){
        cout<<arr[len];
        len--;
    }
    cout<<endl;
    return 0;
}


// code for checking the tree is balanced or not
