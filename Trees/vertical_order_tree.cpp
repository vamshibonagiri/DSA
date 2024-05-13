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
void vert(Node* root,int x,map<int,set<int>>& m){
    if(root==NULL) return ;
    if(m.find(x)==m.end()){
        set<int> v;
        v.insert(root->data);
        m[x]=v;
    }
    else{
        m[x].insert(root->data);
    }
    vert(root->left,x-1,m);
    vert(root->right,x+1,m);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        Node* root=NULL;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            root=insert(root,a[i]);
        }
        map<int,set<int>> m;
        vert(root,0,m);
        for(auto v:m){
            int n=v.second.size();
            for(auto itr=v.second.begin();itr!=v.second.end();itr++){
                cout<<*itr<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
