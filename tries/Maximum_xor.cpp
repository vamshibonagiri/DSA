Given an array of positive integers, find 2 elements such that their xor: a ^ b is maximum.

// Input Format

// First line of input contains T - number of test cases. Its followed by 2T lines - the first line contains N: the size of the array. The second line contains N integers - the elements of the array.

// Constraints

// 50 points
// 1 <= T <= 100
// 2 <= N <= 103
// 0 <= A[i] <= 106

// 150 points
// 1 <= T <= 100
// 2 <= N <= 105
// 0 <= A[i] <= 106

// Output Format

// For each test case, print the value of the maximum xor, separated by new line.

// Sample Input 0

// 2
// 3
// 12 15 9 
// 5
// 13 11 35 3 32 
// Sample Output 0

// 6
// 46
// Explanation 0

// Test Case 1
// You can form the following xor pairs:
// 12^15 = 3, 12^9 = 5, 15^9 = 6 : max = 6
#include <bits/stdc++.h>
using namespace std;
class Node{
  public:
    Node* c[2]={nullptr};
};
Node* insert(Node* root,int n,int b){
    Node* temp=root;
    for(int i=b;i>=0;i--){
        int bit=((n>>i)&1);
        if(temp->c[bit]==NULL)
            temp->c[bit]=new Node();
        temp=temp->c[bit];
    }
    return root;
}
int max_(Node* root,int n,int b){
    int ans=0;
    Node* temp=root;
    for(int i=b;i>=0;i--){
        int bit=((n>>i)&1);
        if(temp->c[1-bit]!=NULL){
            ans+=(1<<i);
            temp=temp->c[1-bit];
        }
        else
            temp=temp->c[bit];
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
        int mx=0;
        Node* root=new Node();
        for(int i=0;i<n;i++){
            cin>>a[i];
            mx=max(mx,a[i]);
        }
        int b=log2(mx),ans=0;
        for(int i=0;i<n;i++){
        root=insert(root,a[i],b);
        ans=max(ans,max_(root,a[i],b));
        }
        cout<<ans<<endl;
        
    }
    return 0;
}
