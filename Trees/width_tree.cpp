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

int width(Node* root){
    if(root==NULL) return 0;
    int ans=0;
    deque<pair<Node*,int>> d;
    d.push_front({root,0});
    d.push_back({NULL,0});
    int mx=INT_MIN,mn=INT_MAX;
    while(!d.empty()){
        pair<Node*,int> pr=d.front();
        d.pop_front();
        Node* tmp=pr.first;
        int x=pr.second;
        if(tmp!=NULL){
            mn=min(mn,x);
            mx=max(mx,x);
            if(tmp->left!=NULL) d.push_back({tmp->left,x-1});
            if(tmp->right!=NULL) d.push_back({tmp->right,x+1});
        }
        else{
            ans=max(ans,abs(mx-mn));
            mx=INT_MIN;
            mn=INT_MAX;
            if(d.size()!=0)
                d.push_back({NULL,0});
        }
    }
    return ans;
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
        int z=width(root);
        cout<<z<<endl;
        
    }
    return 0;
}
