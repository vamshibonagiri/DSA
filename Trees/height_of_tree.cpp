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
Node* insert(Node* root,int val){
    if(root==NULL) return new Node(val);
    else if(root->data>val){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}

int height(Node* root){
    if(root==NULL) return -1;
    return(max(height(root->left),height(root->right))+1);
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
    cout<<height(root)<<endl;
        
    }
    return 0;
}
