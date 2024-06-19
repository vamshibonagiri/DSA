// Perform Insert, delMin and getMin operations on a Min Heap. Implement Min Heaps and avoid using inbuilt library.

// Input Format

// First line of input contains T - number of operations. Its followed by T lines, each line contains either "insert x" or "delMin" or "getMin".

// Constraints

// 1 <= T <= 106
// -109 <= x <= 109

// Output Format

// For each "getMin" operation, print the minimum element, separated by newline. If the heap is empty, print "Empty".

// Sample Input 0

// 10
// insert 5
// getMin
// delMin
// getMin
// insert -15
// insert 10
// insert -30
// getMin
// delMin
// getMin
// Sample Output 0

// 5
// Empty
// -30
// -15
#include <bits/stdc++.h>
using namespace std;

class heap {
public:
    vector<int> v;
    void insert(int x) {
        v.push_back(x);
        int idx = v.size() - 1;
        int pidx = (idx - 1) / 2;
        while (pidx >= 0 && v[pidx] > v[idx]) {
            swap(v[pidx], v[idx]);
            idx = pidx;
            pidx =(pidx - 1)/ 2;
        }
    }

    void getMin() {
        if (v.size() == 0)
            cout << "Empty" << endl;
        else
            cout << v[0] << endl;
    }

    void delMin() {
        if (v.size() == 0)
            return;
        else {
            v[0]=v[v.size()-1];
            v.pop_back();
            if(v.size()==0)
                return;
            int n =v.size();
            int i=0;
            int curr=v[0];
            while (((2*i+1)<n && curr>v[2*i+1])||((2*i+2)<n && curr>v[2*i+2])){
                if(2*i+2<n){
                int idx1 = 2*i+1;
                int idx2 = 2*i+2;
                int mini=idx1;
                if(v[idx1]>v[idx2])
                    mini=idx2;
                swap(v[mini],v[i]);
                i=mini;
                curr=v[i];
                }
                else{
                    swap(v[2*i+1],v[i]);
                    i=2*i+1;
                    curr=v[i];
                }
            }
        }
    }
};

int main() {
    int t;
    cin >> t;
    heap h;
    while (t--) {
        string s;
        cin >> s;
        if (s == "insert") {
            int i;
            cin >> i;
            h.insert(i);
        } else if (s == "getMin")
            h.getMin();
        else
            h.delMin();
    }
    return 0;
}
