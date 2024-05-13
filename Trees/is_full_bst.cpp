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
bool isfull(Node* root){
    if(root==NULL) return true;
     if(root->left==NULL && root->right==NULL)
         return true;
    if(root->left!=NULL && root->right!=NULL)
    return isfull(root->left) && isfull(root->right);
    return false;
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
        if(isfull(root))
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
    }
    return 0;
}
