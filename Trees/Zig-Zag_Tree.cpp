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
vector<vector<int>> zig_zag(Node* root){
    queue<Node*> q;
    vector<vector<int>> res;
    q.push(root);
    q.push(NULL);
    vector<int> ans;
    while(q.size()>0){
        Node* tmp=q.front();
        q.pop();
        if(tmp!=NULL){
            ans.push_back(tmp->data);
            if(tmp->left!=NULL) q.push(tmp->left);
            if(tmp->right!=NULL) q.push(tmp->right);
        }
        else{
            res.push_back(ans);
            ans.clear();
            if(q.size()!=0)
                q.push(NULL);
        }
    }
    return res;
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
        vector<vector<int>> res=zig_zag(root);
        int c=1;
        for(auto v:res){
            int x=v.size();
            if(c%2==0){
                for(int i=0;i<x;i++)
                    cout<<v[i]<<' ';
            }
            else{
                for(int i=x-1;i>=0;i--)
                    cout<<v[i]<<' ';
            }
            c++;
        }
        cout<<endl;
    }
    return 0;
}
