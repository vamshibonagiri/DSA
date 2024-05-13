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
Node* insert(Node* root,int data){
    if(root==NULL) return new Node(data);
    else if(root->data>data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
    return root;
    
}
void leftView(Node* root){
    if(root==NULL) return;
    queue<Node*> s;
    s.push(root);
    s.push(NULL);
    int ans=-1;
    while(!s.empty()){
        Node* tmp=s.front();
        s.pop();
        if(tmp!=NULL){
            if(ans==-1){
                cout<<tmp->data<<' ';
                ans=tmp->data;
            }
            if(tmp->left!=NULL) s.push(tmp->left);
            if(tmp->right!=NULL) s.push(tmp->right);    
        }
        else{
            ans=-1;
            if(s.size()!=0){
            s.push(NULL);
        }
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
        vector<int> v(n);
        Node* root=nullptr;
        for(int i=0;i<n;i++){
            cin>>v[i];
            root=insert(root,v[i]);
        }
        leftView(root);
        cout<<endl;
    }
    return 0;
}
