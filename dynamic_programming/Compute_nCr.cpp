Given n and r, compute nCr.
// Do not use BigInteger class, it defeats the purpose of the problem statement.

// Input Format

// First line of input contains T - number of test cases. Its followed by T lines, each line contains 2 integers - N and R.

// Constraints

// 20 points
// 1 <= T <= 100
// 0 <= N, R <= 30

// 80 points
// 1 <= T <= 500000
// 0 <= N, R <= 2000

// Output Format

// For each test case, print the value of nCr, separated by newline. Since the number can be very large, print result % 1000000007.

// Sample Input 0

// 5
// 4 2
// 3 1
// 25 12
// 30 14
// 6 4
// Sample Output 0

// 6
// 3
// 5200300
// 145422675
// 15
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
    int m=0,n=0;
    int p[t],r[t];
    for(int i=0;i<t;i++){
        cin>>p[i]>>r[i];
        m=max(m,p[i]);
        n=max(n,r[i]);
    }
    int dp[m+1][n+1],mod=1000000007;
    for(int i=0;i<=m;i++)
        dp[i][0]=1;
    for(int i=0;i<=n;i++)
        dp[0][i]=0;
    dp[0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        }
    }
    for(int i=0;i<t;i++){
        cout<<dp[p[i]][r[i]]<<endl;
    }
    return 0;
}
