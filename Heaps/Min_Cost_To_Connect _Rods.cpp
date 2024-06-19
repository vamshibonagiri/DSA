// You are given the lengths of N rods. You want to connect all the rods to form a single rod. The cost of connecting 2 rods of lengths: L1 and L2 is L1+L2. The resultant rod will also be of size L1+L2. Your task is to find the minimum cost to connect all the rods.

// Input Format

// First line of input contains T - number of test cases. Its followed by 2T lines, first line of each test case contains N - the number of rods. The next line contains N integers - the lengths of the rods.

// Constraints

// 30 points
// 1 <= T <= 100
// 1 <= N <= 1000
// 1 <= L[i] <= 1000

// 70 points
// 1 <= T <= 500
// 1 <= N <= 10000
// 1 <= L[i] <= 1000

// Output Format

// For each test case, print the minimum cost to connect all the rods, separated by newline.

// Sample Input 0

// 3
// 3
// 3 1 4
// 2
// 1 2
// 4
// 4 3 2 6
// Sample Output 0

// 12
// 3
// 29
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        priority_queue<int,vector<int>,greater<int>> pq;
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            pq.push(a[i]);
        }
        int ans=0;
        if(n==1)
            cout<<"0"<<endl;
        else{
        while(pq.size()!=0){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            ans+=(x+y);
            if(pq.size()==0)
                break;
            pq.push(x+y);
        }
        cout<<ans<<endl;
        }
    }
    return 0;
}
