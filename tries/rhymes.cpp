Given is a wordlist L, and a word w. Your task is to find the length of the longest word in L having the longest common suffix with w.

// Input Format

// First line of input contains N - length of the list of words. The next N lines contains a single word having lowercase english alphabets. The next line contains Q - number of queries. Each of the next Q lines contains a single word w having lowercase english alphabets.

// Constraints

// 50 points
// 1 <= N, Q <= 1000
// 1 <= len(word) <= 100

// 150 points
// 1 <= N, Q <= 10000
// 1 <= len(word) <= 500

// Output Format

// For each query w, print the length of the longest word having the longest common suffix with w, separated by newline.

// Sample Input 0

// 4
// crime
// fast
// time
// cast
// 3
// dime
// gist
// algorithm
// Sample Output 0

// 5
// 4
// 0
// Explanation 0

// Test Case 1
// Both the words crime and time have the longest common suffix with dime. Hence, length of the longest word is 5.

// Test Case 2
// Both the words fast and cast have the longest common suffix with gist. Hence, length of the longest word is 4.

// Test Case 3
// There is no word in L having a common suffix with algorithm. Hence, length of the longest word is 0.
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* c[26]={nullptr};
    int ct=0;
};
Node* insert(Node* root,string s){
   Node* temp=root;
    int n=s.size();
    for(int i=(n-1);i>=0;i--){
        if(temp->c[s[i]-'a']==NULL)
            temp->c[s[i]-'a']=new Node();
        temp=temp->c[s[i]-'a'];
        temp->ct=max(temp->ct,n);
    }
    return root;
}
int max_(Node* root,string s){
    Node* temp=root;
    for(int i=(s.size()-1);i>=0;i--){
        if(temp->c[s[i]-'a']!=NULL)
            temp=temp->c[s[i]-'a'];
        else
            break;
    }
    return temp->ct;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    Node* root=new Node();
    while(t--){
        string s;
        cin>>s;
        root=insert(root,s);
    }
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        int mx=max_(root,s);
        cout<<mx<<endl;
    }
    return 0;
}
