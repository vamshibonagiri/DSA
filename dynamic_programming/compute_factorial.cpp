// Given a number N, print N!.

// Input Format

// First line of input contains T - number of test cases. Its followed by T lines, each containing a single number N.

// Constraints

// 1 <= T <= 1000000
// 0 <= N <= 1000000

// Output Format

// For each test case, print N!. Since the result can be very large, print N! % 1e9+7.

// Sample Input 0

// 3
// 5
// 20
// 50
// Sample Output 0

// 120
// 146326063
// 318608048
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int m=1e9+7;
int compute(int n,vector<int> &dp){
    if(dp[n]!=-1) return dp[n];
    for(int i=2;i<=n;i++){
        dp[i]=((long)dp[i-1]*i)%m;
    }
    return dp[n];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int q[n];
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>q[i];
        mx=max(mx,q[i]);
    }
    vector<int>dp(mx+1,-1);
    dp[0]=1;
    dp[1]=1;
    int z=compute(mx,dp);
    for(int i=0;i<n;i++){
        cout<<dp[q[i]]<<endl;
    }
    return 0;
}
