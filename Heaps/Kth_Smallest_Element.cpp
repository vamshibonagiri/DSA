#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
            pq.push(a[i]);
        for(int i=0;i<n-k;i++)
            pq.pop();
        cout<<pq.top()<<endl;
        
    }
    return 0;
}
