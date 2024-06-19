Given a standard 6-sided dice, find the number of ways to get a sum of N.

// Input Format

// First line of input contains T - number of test cases. Its followed by T lines, each line contains N - the desired sum.

// Constraints

// 1 <= T <= 100000
// 1 <= N <= 100000

// Output Format

// For each test case, print the number of ways to get a sum of N, separated by newline. Since the answer can be very large, print answer % 1e9+7.

// Sample Input 0

// 5
// 3
// 11
// 7
// 5
// 500
// Sample Output 0

// 4
// 976
// 63
// 16
// 765996555
// Explanation 0

// Test Case 1
// You can get a sum of 3 in the ways:
// (1,1,1), (1,2), (2,1), (3)
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    vector<int> q(t,0);
    int mx=0;
   for(int i=0;i<t;i++){
        cin>>q[i];
        mx=max(mx,q[i]);
    }
    int m=1e9+7;
    vector<int> dp(mx+1,0);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    dp[4]=8;
    dp[5]=16;
    dp[6]=32;
    for(int i=7;i<=mx;i++){
        for(int j = 1;j<7;j++){
            dp[i]=(dp[i]+dp[i-j])%m;
        }
    }
    for(auto n:q){
        cout << dp[n] << endl;
    }
    return 0;
}
