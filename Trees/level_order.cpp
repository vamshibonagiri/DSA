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
void level_level(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        Node* tmp=q.front();
        q.pop();
        if(tmp!=NULL){
            cout<<tmp->data<<' ';
            if(tmp->left!=NULL) q.push(tmp->left);
            if(tmp->right!=NULL) q.push(tmp->right);
        }
        else{
            cout<<'\n';
            if(q.size()!=0)
                q.push(NULL);
        }
    }
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
    level_level(root);
    cout<<endl;
    }
    return 0;
}
