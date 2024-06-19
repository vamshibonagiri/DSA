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
