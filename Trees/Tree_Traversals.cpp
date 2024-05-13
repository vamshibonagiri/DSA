#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};
Node* insert(Node* root,int x){
    if(root==NULL) return new Node(x);
    else if(root->data>x)
        root->left=insert(root->left,x);
    else
        root->right=insert(root->right,x);
    return root;
}
void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node* root=NULL;
        while(n--){
            int x;
            cin>>x;
            root=insert(root,x);
        }
        preorder(root);
        cout<<endl;
        inorder(root);
        cout<<endl;
        postorder(root);
        cout<<endl;
        cout<<endl;
    }
    return 0;
}
