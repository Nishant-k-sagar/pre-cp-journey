#include<bits/stdc++.h>
using namespace std;

void codewithlove() {
    int n, k;
    cin >> n >> k;
    
    if (k == 1) {
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    
    vector<int> res(n);
    vector<bool> used(n + 1, false);
    
    int curr = 1;
    for (int i = 0; i < n; i += k) {
        if (i < n) {
            res[i] = curr++;
            used[res[i]] = true;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (res[i] == 0) {
            while (used[curr]) curr++;
            res[i] = curr++;
            used[res[i]] = true;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        codewithlove();
    }
    
    return 0;
}