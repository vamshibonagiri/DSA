#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    int depth;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};
Node* insert(Node* root,int x,int d){
    if(root==NULL){
        Node* tmp=new Node(x);
        tmp->depth=d;
        return tmp;
    }
    else if(root->data>x)
        root->left=insert(root->left,x,d+1);
    else
        root->right=insert(root->right,x,d+1);
    return root;
}
int search(Node* root,int x){
    if(root==NULL) return -1;
    if(root->data==x)
        return root->depth;
    if(root->data>x)
        return search(root->left,x);
    return search(root->right,x);    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        Node* root=NULL;
        for(int i=0;i<n;i++){
            cin>>a[i];
            root=insert(root,a[i],0);
        }
        for(int i=0;i<n;i++)
            cout<<search(root,a[i])<<' ';
        cout<<endl;
        
    }
    return 0;
}
