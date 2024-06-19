You are given an array of integers of size N. Find the maximum subarray XOR value.

// Input Format

// First line of input contains T - number of test cases. Its followed by 2T lines, the first line contains N - the size of the array. The second line contains the elements of the array.

// Constraints

// 20 points
// 1 <= N <= 103

// 80 points
// 1 <= N <= 105

// General Constraints
// 1 <= T <= 100
// 0 <= A[i] <= 105

// Output Format

// For each test case, print the result, separated by a newline.

// Sample Input 0

// 3
// 3
// 6 3 11 
// 8
// 34 10 10 10 2 8 3 4 
// 7
// 7 9 2 5 8 2 4 
// Sample Output 0

// 14
// 42
// 15
// Explanation 0

// Test Case 1
// The subarrays are:
// [6] : 6
// [6 ^ 3] : 5
// [6 ^ 3 ^ 11] : 14
// [3] : 3
// [3 ^ 11] : 8
// [11] : 11

// The maximum XOR value is 14.
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int mx=0,arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mx=max(mx,arr[i]);
        }
        Node* root=new Node();
        int a=0,b=log2(mx),ans=0;
        root=insert(root,0,b);
        for(int i=0;i<n;i++){
            a=a^arr[i];
            ans=max(ans,max_(root,a,b));
            root=insert(root,a,b);
            
        }
        cout<<ans<<endl;
    }
    return 0;
}
