// You are given an integer K and an array of distinct integers of size N. Find the Kth smallest element from the array.
// Note: Try solving using MaxHeap or Quick Select, don't solve using sorting.

// Input Format

// First line of input contains T - number of test cases. For each test case, the first line contains N - the size of the array. The second line contains N integers - the elements of the array.

// Constraints

// 1 <= T <= 100
// 1 <= K <= N <= 105
// 0 <= A[i] <= 105

// Output Format

// For each test case, print the Kth smallest element from the array, separated by newline.

// Sample Input 0

// 2
// 5 3
// 1 5 13 2 8
// 6 2
// 10 1 20 8 31 12
// Sample Output 0

// 5
// 8
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
