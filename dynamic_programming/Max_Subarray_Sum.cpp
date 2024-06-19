// Given an array of integers, find the maximum subarray sum.

// Input Format

// First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - size of the array and the second line contains N integers - elements of the array.

// Constraints

// 30 points
// 1 <= T <= 100
// 1 <= N <= 10000
// -1000 <= ar[i] <= 1000

// 70 points
// 1 <= T <= 1000
// 1 <= N <= 10000
// -1000 <= ar[i] <= 1000

// Output Format

// For each test case, print the maximum subarray sum, followed by the start and end indices of the subarray, separated by newline. If multiple subarrays give the same sum, consider the lexicographically smaller one for the answer.

// Sample Input 0

// 3
// 9
// -24 0 28 28 55 -31 -27 -45 -24 
// 10
// 40 5 39 45 31 -44 73 -16 -31 27 
// 7
// 57 18 -14 17 31 16 -16 
// Sample Output 0

// 111 1 4
// 189 0 6
// 125 0 5
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int mx = -1001, st = 0;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (mx < a[i]) {
                mx = a[i];
                st = i;
            }
        }

        if (mx < 0) {
            cout << mx << " " << st << " " << st << endl;
            continue;
        }

        
        int idx = 0,end = n - 1, ans = a[0];
        int dp=a[0];
        st=0;

        for (int i = 1; i < n; ++i) {
            if (a[i] > (dp + a[i])) { 
                dp= a[i];
                idx = i;
            } else {
                dp= dp+ a[i];
            }

            if (ans < dp) { 
                ans = dp;
                end = i;
                st=idx;
                
            }
        }

        cout << ans << " " << st << " " << end << endl;
    }

    return 0;
}
