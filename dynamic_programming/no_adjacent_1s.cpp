Find of number of binary strings of length N, such that there are no adjacent 1s in that string.

// Input Format

// First line of input contains T - number of test cases. Its followed by T lines, each line contains N - length of the binary string.

// Constraints

// 1 <= T <= 100000
// 1 <= N <= 100000

// Output Format

// For each test case, print the number of binary strings of length N, separated by newline. Since the answer can be very large, print answer % 1e9+7.

// Sample Input 0

// 5
// 3
// 11
// 7
// 5
// 500
// Sample Output 0

// 5
// 233
// 34
// 13
// 73724597
// Explanation 0

// Test Case 1
// You can construct the following binary strings of length 3 with no adjacent 1s:
// 000, 001, 010, 100, 101
#include <iostream>
#include <algorithm> 
#include<vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int q[n];
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    cin >> q[i];
    mx = max(mx, q[i]); 
  }
  vector<int> dp0(mx+1),dp1(mx+1);
  dp0[0]=1;
  dp1[0]=1;
  int m=1e9+7;
  for(int i=1;i<mx;i++){
        dp0[i]=(dp0[i-1]+dp1[i-1])%m;
        dp1[i]=(dp0[i-1])%m;
    }
  for (int i = 0; i < n; i++) {
    int z = (dp0[q[i]-1] + dp1[q[i]-1]) %m;
    cout << z << endl;
  }

  return 0;
}
