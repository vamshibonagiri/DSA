#include <bits/stdc++.h>
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
int m=1000000007;
Node* insert(Node* root,int x){
    if(root==NULL) return new Node(x);
    else if(root->data>x) root->left=insert(root->left,x);
    else root->right=insert(root->right,x);
    return root;
}
int digits(int n){
    if(n==0) return 1;
    int c=0;
    while(n>0){
        n=n/10;
        c++;
    }
    return c;
}
int sum_tree(Node* root, int val){
    if(root == NULL) return 0;
    val = ((val * (long)pow(10,digits(root->data)))%m + root->data) % m;
    if(root->left == NULL && root->right == NULL)
        return val%m;
    return (sum_tree(root->left, val) +sum_tree(root->right, val) )% m;
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
            root=insert(root,a[i]);
        }
        cout<<sum_tree(root,0)<<endl;
    }
    return 0;
}
