Given an array of integers, find the maximum subsequence sum, such that no 2 elements of the subsequence are adjacent to each other. Note that you cannot select an empty subsequence.

// Input Format

// First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - size of the array and the second line contains N integers - elements of the array.

// Constraints

// 1 <= T <= 1000
// 1 <= N <= 10000
// -1000 <= ar[i] <= 1000

// Output Format

// For each test case, print the maximum subsequence sum, separated by newline.

// Sample Input 0

// 4
// 8
// -24 28 28 55 -31 -27 -45 -24 
// 11
// 40 5 39 45 31 -99 -44 73 -16 -31 27 
// 7
// 57 18 -14 17 31 16 -16 
// 2
// 26 61 
// Sample Output 0

// 83
// 210
// 90
// 61
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],mx=-1001;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mx=max(mx,a[i]);
            
        }
        if(n==1){
            cout<<a[0]<<endl;
            continue;
        }
        if(n==2){
            cout<<max({a[0],a[1]})<<endl;;
            continue;
        }
        if(mx<0){
            cout<<mx<<endl;
        continue;
    }
        int prev=a[0],curr=max(a[0],a[1]);
        for(int i=2;i<n;i++){
            int dp=max(max(prev,prev+a[i]),a[i]);
            prev=max(prev,curr);
            curr=max(dp,curr);
        }
        cout<<curr<<endl;
    }
    return 0;
}
