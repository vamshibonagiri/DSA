#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        this->data=x;
        this->left=nullptr;
        this->right=nullptr;
    }
};
Node* insert(Node* root,int x){
    if(root==NULL) return new Node(x);
    else if(root->data>x) root->left=insert(root->left,x);
    else
        root->right=insert(root->right,x);
    return root;
}
Node* least(Node* root,int a,int b){
    if(root==NULL || root->data==a || root->data==b) return root;
    if (root->data > a and root->data > b)
    return least(root->left,a,b);
    if (root->data < a and root->data < b)
    return least(root->right,a,b);
    return root;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n,z;
        cin>>n>>z;
        vector<int> a(n);
        Node* root=NULL;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            root=insert(root,a[i]);
        }
        while(z--){
            int a,b;
            cin>>a>>b;
            cout<<least(root,a,b)->data<<' ';
        }
        cout<<endl;
        
    }
    return 0;
}
