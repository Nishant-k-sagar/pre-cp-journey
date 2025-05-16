#include<bits/stdc++.h>
using namespace std;

vector<int> constructPermutation(const vector<int>& a) {
    int n = a.size();
    vector<int> p(n);
    set<int> used;

    for (int i = 0; i < n; ++i) {
        if (a[i] >= 0) {
            p[i] = a[i];
            used.insert(a[i]);
        } else {
            int mex = 0;
            while (used.count(mex)) {
                ++mex;
            }
            p[i] = mex;
            used.insert(mex);
        }
    }
    return p;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) {
            cin >> ai;
        }
        vector<int> p = constructPermutation(a);
        for (int pi : p) {
            cout << pi << " ";
        }
        cout << "\n";
    }
    return 0;
}
