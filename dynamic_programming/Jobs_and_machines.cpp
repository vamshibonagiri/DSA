You have to complete N jobs using 2 machines. You can only work on 1 job at a time and the jobs should be completed in the order given in the input. The time to complete a particular job is different on Machine-1 and Machine-2. Also, there is a switching time of K involved between the machines. Find the minimum time required to complete all the jobs.

// Input Format

// First line of input contains T - number of test cases. First line of each testcase contains 2 integers N and K, it's followed by 2 lines, each containing N integers where ith number in each line denotes the time taken by the Machine-1 and Machine-2 to complete the ith job respectively.

// Constraints

// 1 <= T <= 103
// 1 <= N, K <= 103
// 1 <= A[i], B[i] <= 105

// Output Format

// For each test case, print the minimum time to complete all the jobs, separated by new line.

// Sample Input 0

// 2
// 5 8
// 11 34 50 29 17 
// 36 48 27 13 18 
// 5 2
// 18 23 44 37 36 
// 46 29 42 45 8 
// Sample Output 0

// 111
// 132
// Explanation 0

// Test Case 1

// Jobs will be executed in the following order: Machine-1, Machine-1, Machine-2, Machine-2, Machine-2.

// Total Cost = 11 + 34 + 8 + 27 + 13 + 18 = 111.

// Test Case 2

// Jobs will be executed in the following order: Machine-1, Machine-1, Machine-1, Machine-1, Machine-2.

// Total Cost = 18 + 23 + 44 + 37 + 2 + 8 = 132.
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
    int n,k;
    cin>>n>>k;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int p=0,c=0,ja=0,jb=0;
    for(int i=0;i<n;i++){
        int tp=p,tc=c;
        p=min(p,tc+k)+a[i];
        c=min(c,tp+k)+b[i];;
        ja=ja+a[i];
        jb+=b[i];
    }
    cout<<min({p,c,ja,jb})<<endl;
    }
    return 0;
}
