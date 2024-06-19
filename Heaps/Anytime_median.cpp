// Given an integer array, print the median for the sub-array 0 to i, for every i, 0<=i<=N-1.

// Input Format

// First line of input contains T - number of test cases. Its followed by 2T lines - the first line contains N - the size of the array. The second line contains N integers - the elements of the array.

// Constraints

// 30 points
// 1 <= T <= 100
// 1 <= N <= 103

// 70 points
// 1 <= T <= 100
// 1 <= N <= 104

// General Constraints
// -104 <= A[i] <= 104

// Output Format

// For each test case, print the median for the sub-array 0 to i, for every i, separated by space. Print new line between output of different test cases.
// Note: In case of even length sub-array, print the smaller element as the median.

// Sample Input 0

// 2
// 5
// -10 14 11 -5 7 
// 3
// 2 -5 14 
// Sample Output 0

// -10 -10 11 -5 7 
// 2 -5 2 
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        priority_queue<int> h1;
        priority_queue<int,vector<int>,greater<int>> h2;
        for(int i=0;i<n;i++){
            if(h1.size()==0 || h1.top()>a[i])
                h1.push(a[i]);
            else
                h2.push(a[i]);
            int m=h1.size();
            int n=h2.size();
            if((m-n)<0)
            {
                h1.push(h2.top());
                h2.pop();
            }
            else if(((m-n)>1))
            {
                h2.push(h1.top());
                h1.pop();
            }
            cout<<h1.top()<<' ';
        }
        cout<<endl;
        
    }
    return 0;
}
