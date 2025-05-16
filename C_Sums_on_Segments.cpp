#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void codewithlove() {
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    set<int> ans;
    ans.insert(0);

    for (int i = 0; i < n; i++) {
        ans.insert(v[i]);
    }

    int idx = -1;

    for (int i = 0; i < n; i++) {
        if (v[i] != 1 && v[i] != -1) {
            idx = i;
        }
    }

    int sum = 0;
    if (idx != -1) {
        for (int i = idx; i >= 0; i--) {
            sum += v[i];
            ans.insert(sum);
        }

        sum = 0;
        for (int i = idx; i < n; i++) {
            sum += v[i];
            ans.insert(sum);
        }
    }

    cout << ans.size() << endl;
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        codewithlove();
    }

    return 0;
}
