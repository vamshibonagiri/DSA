// There is a line of houses, where each house can be painted with one of the three colors: red, blue and green. The cost of painting each house with a certain color is different. Find the minimum cost to paint all the houses such that no two adjacent house have the same color.

// Input Format

// First line of input contains T - number of test cases. Its followed by 4T lines, the first line contains N - number of houses and the second, third and fourth line contains the costs of each house for red, green and blue respectively.

// Constraints

// 1 <= T <= 100
// 1 <= N <= 103
// 1 <= R[i],G[i],B[i] <= 103

// Output Format

// For each test case, print the minimum cost, separated by newline.

// Sample Input 0

// 1
// 6
// 7 3 8 6 1 2 
// 5 6 7 2 4 3 
// 10 1 4 9 7 6 
// Sample Output 0

// 18
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> red(n), green(n), blue(n);
        for (int i = 0; i < n; i++) {
            cin >> red[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> green[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> blue[i];
        }

        vector<int> dpr(n), dpg(n), dpb(n);
        dpr[0] = red[0];
        dpg[0] = green[0];
        dpb[0] = blue[0];

        for (int i = 1; i < n; i++) {
            dpr[i] = min(dpg[i-1], dpb[i-1]) + red[i];
            dpg[i] = min(dpr[i-1], dpb[i-1]) + green[i];
            dpb[i] = min(dpr[i-1], dpg[i-1]) + blue[i];
        }

        int ans = min({dpr[n-1], dpg[n-1], dpb[n-1]});
        cout << ans << endl;
    }
    return 0;
}
